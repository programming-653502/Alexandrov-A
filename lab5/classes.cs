using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab5_1_
{
    public class Node
    {
        public int Digit { get; set; }
        public Node Prev { get; set; }
        public Node Next { get; set; }

        public Node(int digit)
        {
            Digit = digit;
            Prev = null;
            Next = null;
        }
    }

    public class MyList
    {
        protected Node _start;
        protected int _length;

        public Node Start
        {
            get
            {
                return _start;
            }
        }

        public int Length
        {
            get
            {
                return _length;
            }
        }

        protected Node GetNode(int index)
        {

            if (index < 0 || index > Length - 1)
            {
                throw new Exception("out of range");
            }
            Node slider = _start;
            for (int i = 1; i <= index; i++)
            {
                slider = slider.Next;
            }

            return slider;
        }

        public int this[int index]
        {


            get
            {
                return GetNode(index).Digit;
            }
            set
            {

                Node IndexNode = GetNode(index);
                IndexNode.Digit = value;

            }
        }

        public void Push(int digit)
        {
            if (_length == 0)
            {
                _start = new Node(digit);
                _length++;
            }
            else
            {
                Node NewNode = new Node(digit);
                NewNode.Prev = GetNode(_length - 1);
                NewNode.Prev.Next = NewNode;
                _length++;
            }
        }

        public void Pop()
        {
            if (Length != 0)
            {
                Node LastNode = GetNode(_length - 1);
                LastNode = null;
                _length--;
            }
        }

        public void InsertToStart(int digit)
        {
            if (_length == 0)
            {
                _start = new Node(digit);
                _length++;
            }
            else
            {
                Node NewNode = new Node(digit);
                NewNode.Next = _start;
                _start.Prev = NewNode;
                _start = NewNode;
                _length++;
            }
        }


    }

    public class LongNumber : MyList
    {

        public static bool operator >=(LongNumber number1, LongNumber number2)
        {
            if (number1.Length > number2.Length)
            {
                return true;
            }
            else
            {
                if (number1.Length < number2.Length)
                {
                    return false;
                }
                else
                {

                    for (int i = number1.Length - 1; i >= 0; i--)
                    {
                        if (number1[i] > number2[i])
                        {
                            return true;
                        }
                        if (number1[i] < number2[i])
                        {
                            return false;
                        }
                    }


                    return true;
                }
            }
        }

        public static bool operator <=(LongNumber number1, LongNumber number2)
        {
            return number2 >= number1;
        }

        public static bool operator ==(LongNumber number1, LongNumber number2)
        {
            return number1 >= number2 && number1 <= number2;
        }

        public static bool operator !=(LongNumber number1, LongNumber number2)
        {
            return !(number1 == number2);
        }
        public static bool operator >(LongNumber number1, LongNumber number2)
        {
            return number1 >= number2 && number1 != number2;
        }

        public static bool operator <(LongNumber number1, LongNumber number2)
        {
            return number1 <= number2 && number1 != number2;
        }

        public static LongNumber operator -(LongNumber number1, LongNumber number2)
        {

            if (number1 < number2)
            {
                return null;
            }

            if (number1 == number2)
            {
                return new LongNumber(0);
            }

            LongNumber result = new LongNumber(0);


            for (int i = 0; i < number1.Length; i++)
            {

                if (i < number1.Length - 1)
                {
                    result.Push(0);
                    (result)[i + 1] = (result)[i + 1] - 1;
                    (result)[i] = (result)[i] + 10 + number1[i];
                }
                else
                {
                    result[i] = result[i] + number1[i];
                }

                if (i < number2.Length)
                {
                    result[i] = result[i] - number2[i];
                }

                if (result[i] / 10 > 0 && i < number1.Length - 1)
                {
                    ((MyList)result)[i + 1] = ((MyList)result)[i + 1] + 1;
                    result[i] = result[i] % 10;
                }


            }

            int j = result.Length - 1;

            while (result[j] <= 0 && j > 0)
            {
                result.Pop();
                j--;

            }


            return result;

        }

        public static LongNumber operator %(LongNumber number1, LongNumber number2)
        {
            if (number1 == number2)
            {
                return new LongNumber(0);
            }

            if (number1 < number2)
            {
                return GetCopy(number1);
            }


            int i = number1.Length - 1;
            LongNumber temp = new LongNumber();
            while (i >= 0)
            {
                temp.InsertToStart(number1[i]);
                i--;
                if (temp[temp.Length - 1] == 0 && temp.Length > 1)
                {
                    temp.Pop();
                }

                while (temp < number2 && i >= 0)
                {
                    temp.InsertToStart(number1[i]);
                    i--;
                }


                while (temp >= number2)
                {
                    temp = temp - number2;
                }

            }


            return temp;
        }

        public static LongNumber LeastCommonDivisor(LongNumber number1, LongNumber number2)
        {


            if (number1 >= number2)
            {
                LongNumber temp = number1 % number2;
                if (temp == new LongNumber(0))
                {
                    return GetCopy(number2);
                }
                return LeastCommonDivisor(number2, temp);
            }
            else
            {
                LongNumber temp = number2 % number1;
                if (temp == new LongNumber(0))
                {
                    return GetCopy(number1);
                }
                return LeastCommonDivisor(number1, temp);
            }
        }

        public static bool MuTuallySimple(LongNumber number1, LongNumber number2)
        {
            if (number1 == new LongNumber(0) || number2 == new LongNumber(0))
            {
                return false;
            }
            return LeastCommonDivisor(number1, number2) == new LongNumber(1);
        }

        public LongNumber(string string_number) : this()
        {

            char char_digit;
            if (string_number[0] == '-')
            {
                string_number = string_number.Remove(0, 1);
            }
            for (int i = string_number.Length - 1; i >= 0; i--)
            {

                char_digit = string_number[i];
                int digit = 0;
                try
                {
                    digit = Int32.Parse(char_digit.ToString());
                }
                catch (Exception)
                {
                    Console.WriteLine("Wrong input");
                    Console.ReadKey();
                    Environment.Exit(1);
                }

                Push(digit);

            }
        }
        public LongNumber(int number) : this(number.ToString()) { }

        public LongNumber()
        {
            _start = null;
            _length = 0;
        }


        public static LongNumber GetCopy(LongNumber MyList1)
        {
            LongNumber temp = new LongNumber();
            for (int i = 0; i < MyList1.Length; i++)
            {
                temp.Push(MyList1[i]);
            }
            return temp;
        }

    }
}
