using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace Cache
{
    class Cache<T>
    {
        private int maxSize;
        private TimeSpan lifeTime;
        private Dictionary<string, Tuple<T, DateTime>> memory;

        public Cache(TimeSpan time, int size)
        {
            memory = new Dictionary<string, Tuple<T, DateTime>>();
            lifeTime = time;
            maxSize = size;
        }

        private void RemoveTimeoutElements()
        {
            TimeSpan interval;
            DateTime creationTime;
            DateTime currentTime;

            foreach (var element in memory)
            {
                currentTime = DateTime.Now;
                creationTime = element.Value.Item2;
                interval = currentTime - creationTime;
                if (interval >= lifeTime)
                    memory.Remove(element.Key);
            }
        }

        private void RemoveOldestElement()
        {
            TimeSpan maxInterval = new TimeSpan(0);
            DateTime currentTime = DateTime.Now;
            DateTime creationTime;
            string oldestKey = null;

            foreach (var element in memory)
            {
                creationTime = element.Value.Item2;
                if (currentTime - creationTime > maxInterval)
                {
                    maxInterval = currentTime - creationTime;
                    oldestKey = element.Key;
                }
            }
            memory.Remove(oldestKey);
        }

        public void Save(string key, T data)
        {
            Tuple<T, DateTime> value;

            RemoveTimeoutElements();
            if (memory.TryGetValue(key, out value))
            {
                throw new ArgumentException();
            }
            else if (memory.Count == maxSize)
            {
                RemoveOldestElement();
                memory.Add(key, new Tuple<T, DateTime>(data, DateTime.Now));
            }
            else
            {
                memory.Add(key, new Tuple<T, DateTime>(data, DateTime.Now));
            }
        }

        public T Get(string key)
        {
            Tuple<T, DateTime> value;

            RemoveTimeoutElements();
            if (!memory.TryGetValue(key, out value))
                throw new KeyNotFoundException();
            return value.Item1;
        }
    }
}