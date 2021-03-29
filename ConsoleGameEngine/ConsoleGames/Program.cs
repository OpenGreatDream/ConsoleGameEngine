using System;

using ConsoleGameEngine;

using Vanara.PInvoke;

using static Vanara.PInvoke.Kernel32;
using static Vanara.PInvoke.User32;

namespace ConsoleGames
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Load Native DLL:" + ConTest.LoadNativeDLL());
            Console.WriteLine("BuildMode:" + ConTest.BuildModeString());

            Audio.AudioPlayOneShot("..\\..\\..\\..\\..\\resources\\BOBACRI - Sleep Away.mp3");

            Console.ReadLine();
        }
    }
}
