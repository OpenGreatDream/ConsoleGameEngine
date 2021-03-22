#pragma once

#include "ConTest.h"
#include <string>

namespace ConsoleGameEngineNative
{
    class Audio
    {
    public:
        static bool PlayOneShot(const std::wstring& path, double defaultVolume = 1.0);

    private:
        static bool inited;

    public:
        Audio(const std::wstring& path, double defaultVolume = 1.0);

        ~Audio();

        bool Play(bool repeat = false);

        bool Pause();

        //0=mute, 1.0=normal, 1.0 and above=enlarge
        double GetVolume();

        //0=mute, 1.0=normal, 1.0 and above=enlarge
        bool SetVolume(double volume);

        //second
        double GetPosition();

        //second
        bool SetPosition(double sec);

        //Absolute path
        std::wstring GetAudioPath();

        //second
        double GetAudioLength();

        bool IsPlaying();

        bool IsAudioOver();

    public:
        bool repeat;
        bool destroy_on_end;

    private:
        std::wstring path;
        double audio_length;
        bool isPlaying;
        unsigned int audio_stream;
    };

    EXPORT_FUNC AudioPlayOneShot(wchar_t* path, double defaultVolume = 1.0);
}