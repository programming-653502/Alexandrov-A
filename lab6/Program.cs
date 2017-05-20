using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    class Program
    {
 
        static void Main(string[] args)
        {
            Console.WriteLine("Enter strings");
            BinaryTree MyBinTree = new BinaryTree();  
            MyList MyList1 = new MyList(MyBinTree);
            MyBinTree.PrintElements();
            MyList1.Print();

            Console.ReadKey();
        }
    }
}
