using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5_1_
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("first number");
            string string_number1 = Console.ReadLine();
            Console.WriteLine("second number");
            string string_number2 = Console.ReadLine();
            LongNumber number1 = new LongNumber(string_number1);
            LongNumber number2 = new LongNumber(string_number2);
            if (LongNumber.Simple(number1, number2))
            {
                Console.WriteLine("\nMutually \n");
            }
            else
            {
                Console.WriteLine("\nNot mutually \n");
            }
            Console.ReadKey();
        }
    }
}
