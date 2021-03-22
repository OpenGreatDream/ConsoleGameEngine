using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleGameEngine
{
    public class Audio
    {
        [DllImport("ConsoleGameEngineNative.dll",
            CallingConvention = CallingConvention.StdCall,
            SetLastError = true,
            EntryPoint = "AudioPlayOneShot",
            CharSet = CharSet.Unicode)]
        public extern static bool AudioPlayOneShot(string path, double defaultVolume = 1.0);
    }
}
