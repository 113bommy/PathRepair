from queue import Queue
def find_winner(q, n, k):
    p1 = q.get()
    c = 0
    while c < k:
        p2 = q.get()
        while c < k and p1 > p2:
            c += 1
            q.put(p2)
            p2 = q.get()
        if c >= k:
            return p1
        else:
            q.put(p1)
            p1 = p2
            c = 0


n, k = [int(num) for num in input().strip().split()]
q = Queue()
m = 0
for val in input().strip().split():
    m = max(m, int(val))
    q.put(int(val))
if n < k:
    print(m)
else:
    print(find_winner(q, n, k))
