import queue

q = queue.Queue()
n, b = map(int, input().split())
t = 0
d = 0
process_time = 0
for i in range(n):
    t, d = map(int, input().split())
    while not q.empty() and q.queue[0] <= t:
        q.get()
    if q.qsize() <= b:
        if process_time < t:
            process_time = t
        process_time += d
        print(process_time, end = ' ')
        q.put(process_time)
    else:
        print('-1 ', end = '')