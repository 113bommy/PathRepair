from collections import deque

n, queue_size = map(lambda x: int(x), input().split())

results = [-1 for _ in range(n)]

next_server_free_time = 1
queue = deque()
for idx in range(n):
    t, d = map(lambda x: int(x), input().split())

    while queue and next_server_free_time <= t:
        idx1, d1 = queue.popleft()
        next_server_free_time += d1
        results[idx1] = next_server_free_time

    if next_server_free_time <= t:
        results[idx] = t + d
        next_server_free_time = t + d
    else:
        if len(queue) < queue_size:
            queue.append((idx, d))

while queue:
    idx, d = queue.popleft()
    next_server_free_time += d
    results[idx] = next_server_free_time

print(' '.join(map(lambda x: str(x), results)))
