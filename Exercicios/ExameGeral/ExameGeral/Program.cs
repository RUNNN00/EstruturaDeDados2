using System;
using System.Collections.Generic;

namespace ExameGeral
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            int q;

            string[] nums = Console.ReadLine().Split(' ');
            n = int.Parse(nums[0]);
            q = int.Parse(nums[1]);

            List<int> notas = new List<int>();
            notas.Add(30000);
            
            for (int i = 0; i < n; i++)
            {
                int nota = int.Parse(Console.ReadLine());
                notas.Add(nota);
            }

            notas.Sort();
            notas.Reverse();

            List<int> consultadas = new List<int>();
            for (int i = 0; i < q; i++)
            {
                int index = int.Parse(Console.ReadLine());
                consultadas.Add(notas[index]);
            }

            foreach(int nota in consultadas)
            {
                Console.WriteLine(nota);
            }
        }
    }
}
