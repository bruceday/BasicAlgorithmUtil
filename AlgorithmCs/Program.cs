using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmCs
{
    class Program
    {
        static void Main(string[] args)
        {
            PriorityQueue<int> qp = new PriorityQueue<int>();
            qp.Push(1);
            qp.Push(22);
            qp.Push(3);
            qp.Push(44);
            qp.Push(5);
            qp.Push(66);
            while (qp.Count != 0)
            {
                Console.Write(qp.Top()+" ");
                qp.Pop();
            }
            Console.Read();

        }
    }
}
