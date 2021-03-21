using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleGameEngine
{
    public class ConTest
    {
        public static string BuildModeString()
        {
            string str = string.Empty;
#if DEBUG
            testString += "DEBUG";
#else
            str += "RELEASE";
#endif
            return str;
        }

        public static bool IsWindows()
        {
            //return RuntimeInformation.IsOSPlatform(OSPlatform.Windows);
            return OperatingSystem.IsWindows();
        }
    }
}
