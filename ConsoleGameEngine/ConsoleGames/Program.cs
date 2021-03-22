using System;

using ConsoleGameEngine;
using ConsoleGameEngine.Include;

using static ConsoleGameEngine.Include.NativeMethods;

namespace ConsoleGames
{
    class Program
    {
        static void Main(string[] args)
        {
            IntPtr hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
            CHAR_INFO[] charInfos = new CHAR_INFO[20];
            for (int i = 0; i < charInfos.Length; i++)
            {
                charInfos[i].Attributes = 7;
                charInfos[i].UnicodeChar = 'a';
            }
            SMALL_RECT rect = new SMALL_RECT() { Left = 0, Top = 0, Bottom = 1, Right = 9 };
            bool s = WriteConsoleOutput(hOutput, charInfos,
                new COORD() { X = 10, Y = 2 }, new COORD() { X = 0, Y = 0 }, ref rect);

            bool suc = ConTest.TryToLoadNativeDLL();
            Console.WriteLine("Load Native DLL:" + suc);

            string str = ConTest.BuildModeString();
            Console.WriteLine(str);

            Console.WriteLine("Hello World!");
            
            Console.ReadLine();
        }
    }
}
