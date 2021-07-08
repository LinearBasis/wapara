using System;
using System.IO;
using System.Text;

namespace logger
{
    public enum severity
    {
        trace,
        debug,
        information,
        warning,
        error,
        critical
    }

    public class Logger : IDisposable
    {
        private sealed class DisposableImplementation : IDisposable
        {
            private StreamWriter _stream;

            public DisposableImplementation(string path)
            {
                _stream = new StreamWriter(path);
            }

            public void Log(severity lvl, string msg)
            {
                StringBuilder sb = new StringBuilder();

                sb.Append("[");
                sb.Append(DateTime.Now.ToString());
                sb.Append("][");
                sb.Append(lvl.ToString());
                sb.Append("]: ");
                sb.Append(msg);
                _stream.WriteLine(sb);
            }

            public void Dispose()
            {
                _stream.Dispose();
            }

        }

        private DisposableImplementation _d;

        public Logger(string path)
        {
            _d = new DisposableImplementation(path);
        }

        public void Log(severity lvl, string msg)
        {
            _d.Log(lvl, msg);
        }

        public void Dispose()
        {
            _d.Dispose();
            GC.SuppressFinalize(this);
        }
    }
}