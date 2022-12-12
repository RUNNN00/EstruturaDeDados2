using System;
using System.Collections.Generic;

namespace ListaDeChamadas
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] values = Console.ReadLine().Split(' ');
            int n = int.Parse(values[0]);
            int k = int.Parse(values[1]);
            List<string> nomes = new List<string>();

            for (int i = 0; i < n; i++)
                nomes.Add(Console.ReadLine());

            nomes.Sort();
            Console.WriteLine(nomes[k - 1]);
        }
    }
}
