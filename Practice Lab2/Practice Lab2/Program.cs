using System;
using System.IO;
using logger;
using System.Collections.Generic;
using System.Linq;

namespace lab2
{
    class Program
    {
        // for commit
        static void Main(string[] args)
        {
            using (var log = new Logger(Path.Combine(Environment.CurrentDirectory, "logfile.txt")))
            {
                log.Log(severity.trace, "File created");
                log.Log(severity.debug, "Compiled successfully");
                log.Log(severity.information, "=)");
                log.Log(severity.warning, "Incorrect cast");
                log.Log(severity.error, "Compilation fail");
                log.Log(severity.critical, "SSD is damaged");
                log.Log(severity.trace, "Deleted file");
                log.Log(severity.information, "Processor - Intel Core i5 8250U");
                Console.WriteLine("Successfully created logfile.txt in \\lab2\\bin\\Debug\\netcoreapp3.1");
            }
        }
    }
}