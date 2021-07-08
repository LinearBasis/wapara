using System;
using Cache;


namespace Practice_Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            TimeSpan lifeTime = new TimeSpan(0, 1, 0, 0, 0);
            Cache<string> appCache = new Cache<string>(lifeTime, 3);

            /* Filling cache with 5 elements */
            try
            {
                appCache.Save("1", "1st");
                appCache.Save("2", "2nd");
                appCache.Save("3", "3rd");
                appCache.Save("4", "4th");
                Console.WriteLine("All added");
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine("Save error: " + ex.Message);
            }
            try
            {
                appCache.Get("2");
                Console.WriteLine("Got 2");
                appCache.Get("3");
                Console.WriteLine("Got 3");
                appCache.Get("4");
                Console.WriteLine("Got 4");
                appCache.Get("1");
                Console.WriteLine("Got 1");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Get error: " + ex.Message);
            }
        }
    }
}

