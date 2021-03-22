#include "Audio.h"

//using BASS lib
#include "bass.h"
#pragma comment(lib, "bass.lib")

namespace ConsoleGameEngineNative
{
    void CALLBACK DefaultSyncProc(DWORD handle, DWORD channel, DWORD data, void* user)
    {
        Audio* audiox = (Audio*)user;

        if (audiox->destroy_on_end)
        {
            delete audiox;
            return;
        }

        if (audiox->repeat)
        {
            audiox->SetPosition(0);
            audiox->Play(true);
        }
    }

    bool Audio::PlayOneShot(const std::wstring& path, double defaultVolume)
    {
        Audio* audio_ptr = new Audio(path, defaultVolume);
        audio_ptr->destroy_on_end = true;
        bool suc = audio_ptr->Play(false);
        return suc;
    }

    bool Audio::inited = false;

    Audio::Audio(const std::wstring& path, double defaultVolume)
    {
        if (!inited)
        {
            //you can use BASS_Free to release it
            bool init_suc = BASS_Init(-1, 44100, 0, nullptr, nullptr);
            if (init_suc)
            {
                inited = true;
            }
        }

        this->path = path;
        this->audio_stream = BASS_StreamCreateFile(false, path.c_str(), 0, 0, 0);
        this->isPlaying = false;
        this->repeat = false;
        this->destroy_on_end = false;

        QWORD len_bytes = BASS_ChannelGetLength(audio_stream, BASS_POS_BYTE);
        this->audio_length = BASS_ChannelBytes2Seconds(audio_stream, len_bytes);

        BASS_ChannelSetSync(audio_stream, BASS_SYNC_END, 0, DefaultSyncProc, this);

        this->SetVolume(defaultVolume);
    }

    Audio::~Audio()
    {
        BASS_StreamFree(audio_stream);
    }

    bool Audio::Play(bool repeat)
    {
        this->repeat = repeat;

        bool suc = BASS_ChannelPlay(audio_stream, false);
        if (suc)
            isPlaying = true;
        return suc;
    }

    bool Audio::Pause()
    {
        bool suc = BASS_ChannelPause(audio_stream);
        if (suc)
            isPlaying = false;
        return suc;
    }

    double Audio::GetVolume()
    {
        float vol = 0.0f;
        BASS_ChannelGetAttribute(audio_stream, BASS_ATTRIB_VOL, &vol);
        return vol;
    }

    bool Audio::SetVolume(double volume)
    {
        return BASS_ChannelSetAttribute(audio_stream, BASS_ATTRIB_VOL, static_cast<float>(volume));
    }

    double Audio::GetPosition()
    {
        QWORD pos_bytes = BASS_ChannelGetPosition(audio_stream, BASS_POS_BYTE);
        double sec = BASS_ChannelBytes2Seconds(audio_stream, pos_bytes);
        return sec;
    }

    bool Audio::SetPosition(double sec)
    {
        QWORD pos_bytes = BASS_ChannelSeconds2Bytes(audio_stream, sec);
        return BASS_ChannelSetPosition(audio_stream, pos_bytes, BASS_POS_BYTE);
    }

    std::wstring Audio::GetAudioPath()
    {
        return path;
    }

    double Audio::GetAudioLength()
    {
        return audio_length;
    }

    bool Audio::IsPlaying()
    {
        return isPlaying;
    }

    bool Audio::IsAudioOver()
    {
        double pos = GetPosition();
        double diff = abs(audio_length - pos);

        if (isPlaying && diff < 0.001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    EXPORT_FUNC AudioPlayOneShot(wchar_t* path, double defaultVolume)
    {
        return Audio::PlayOneShot(path, defaultVolume);
    }
}