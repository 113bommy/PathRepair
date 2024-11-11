import queue
q = queue.Queue()
n, b = map(int, input().split())
processing, qlen = 0, 0             # Dùng qsize bị TLE

for _ in range(n):
    t, d = map(int, input().split())

    while qlen != 0 and q.queue[0] <= t:
        q.get()
        qlen -= 1
    
    if qlen <= b:
        processing = max(processing, t) + d
        print(processing, end=' ')
        q.put(processing)
        qlen += 1
    else:
        print(-1, end=' ')