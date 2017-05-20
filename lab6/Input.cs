using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    public static class Input
    {
        public static void _Input<T>(ref T variable)
        {
            bool RightInput = MyTryParse(Console.ReadLine(), ref variable);
            while (!RightInput)
            {
                Console.WriteLine("wrong input,try again");
                RightInput = MyTryParse(Console.ReadLine(), ref variable);

            }
        }

        public static bool MyTryParse<T>(string s, ref T variable)
        {
            try
            {
                variable = (T)Convert.ChangeType(s, typeof(T));
            }
            catch
            {
                return false;
            }
            return true;
        }

        
    }
}
