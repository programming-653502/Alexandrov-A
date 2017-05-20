using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    internal class NodeOfList
    {
        public string Info;
        public NodeOfList Previous;
        public NodeOfList Next;
        private int _sum_codes;
        public int SumCodes
        {
            get
            {
                return _sum_codes;
            }
        }

        public NodeOfList(string info)
        {
            Previous = null;
            Next = null;
            Info = info;
            _sum_codes = SumOfCodes.GetSum(info);
        }

    }

    public class MyList
    {
        private NodeOfList _start;
        private int _length;



        public int Length
        {
            get
            {
                return _length;
            }
        }

        private NodeOfList GetNodeOfList(int index)
        {

            NodeOfList slider = _start;
            for (int i = 1; i <= index; i++)
            {
                slider = slider.Next;
            }

            return slider;
        }

        private NodeOfList GetNodeOfList(string s)
        {

            NodeOfList slider = _start;
            for (int i = 1; i <= _length; i++)
            {
                if (slider.Info == s)
                {
                    return slider;
                }
                slider = slider.Next;
            }

            return null;

        }

        public string this[string s]
        {


            set
            {

                NodeOfList IndexNodeOfList = GetNodeOfList(s);
                if (IndexNodeOfList != null)
                {
                    IndexNodeOfList.Info = value;
                }

            }
        }

        public void Push(string str)
        {
            if (_length == 0)
            {
                _start = new NodeOfList(str);
                _length++;
            }
            else
            {
                NodeOfList NewNodeOfList = new NodeOfList(str);
                NewNodeOfList.Previous = GetNodeOfList(_length - 1);
                NewNodeOfList.Previous.Next = NewNodeOfList;
                _length++;
            }
        }
                  


        public void Print()
        {
            Console.WriteLine("\nelements of the stack are\n\n");
            NodeOfList slider = _start;
            if (_length == 0)
            {
                Console.WriteLine("\nthe stack is empty\n");
                return;
            }
            for (int i = 0; i < Length; i++)
            {
                Console.WriteLine(slider.Info + " sum of codes is " + slider.SumCodes.ToString() + "\n");
                slider = slider.Next;
            }
            Console.WriteLine("\n");

        }

        public MyList(BinaryTree MyBinaryTree)
        {
            MyBinaryTree.MakeList(this);
        }

        internal void Push(Node node1)
        {
            if (SumOfCodes.EvenSum(node1.Info))
            {
                this.Push(node1.Info);
            }
        }
    
    }
}