using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace lab6
{

    internal class Node
    {

        public string Info;
        public Node LeftChild;
        public Node RightChild;
        private int _sum_codes;
        public int SumCodes
        {
            get
            {
                return _sum_codes;
            }
        }
        
        public Node(string s)
        {
            LeftChild = null;
            RightChild = null;
            Info = s;
            _sum_codes = SumOfCodes.GetSum(s);

        }

    }

    public class BinaryTree
    {
        private Node _root;

        internal Node Root
        {
            get
            {
                return _root;
            }
        }

        public BinaryTree()
        {
            _root = new Node(Console.ReadLine());
            Console.WriteLine("\npress any key\n");
            Console.ReadKey();
            Console.Clear();
            CreateTree();

        }

        private void CreateTree()
        {
            bool Continue = true;
            Console.WriteLine("if you want to add a new element enter \"true\" else enter \"false\"\n");
            Input._Input<bool>(ref Continue);
            while (Continue)
            {
                Add(Console.ReadLine());
                Console.WriteLine("\npress any key\n");
                Console.ReadKey();
                Console.Clear();
                Console.WriteLine("if you want to add a new element enter \"true\" else enter \"false\"");
                Input._Input<bool>(ref Continue);
            }
        }


        private void PrintInfo(Node node1)
        {
            Console.WriteLine(node1.Info + "  sum of codes is " + (node1.SumCodes).ToString() + "\n");
        }


        internal void Add(Node node1, string s)
        {

            if (SumOfCodes.GetSum(s) <= node1.SumCodes)
            {
                if (node1.LeftChild == null)
                {
                    node1.LeftChild = new Node(s);
                }
                else
                {
                    Add(node1.LeftChild, s);
                }
            }
            else
            {
                if (node1.RightChild == null)
                {
                    node1.RightChild = new Node(s);
                }
                else
                {
                    Add(node1.RightChild, s);
                }
            }

        }

        public void Add(string s)
        {
            if (_root == null)
            {
                _root = new Node(s);
            }
            else
            {
                Add(_root, s);
            }
        }

        internal delegate void function(Node node1);

        internal void Operation(Node node1, function f)
        {
            if (node1 != null)
            {
                f.Invoke(node1);
                if (node1.LeftChild != null)
                {
                    Operation(node1.LeftChild, f);
                }
                if (node1.RightChild != null)
                {
                    Operation(node1.RightChild, f);
                }
            }
        }

        public void PrintElements()
        {
            Console.WriteLine("\n\nelements of the tree are\n\n");
            function f = PrintInfo;
            Operation(_root, f);
            Console.WriteLine("\n");
        }

        public void MakeList(MyList list)
        {
            function f = list.Push;
            Operation(_root, f);
            Console.WriteLine("\n\n");

        }






    }
}