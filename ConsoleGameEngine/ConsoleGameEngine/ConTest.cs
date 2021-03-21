using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleGameEngine
{
    public class ConTest
    {
        public static string BuildModeString()
        {
            string testString = string.Empty;
#if DEBUG
            testString += "DEBUG";
#else
            testString += "RELEASE";
#endif
            return testString;
        }
    }
}
