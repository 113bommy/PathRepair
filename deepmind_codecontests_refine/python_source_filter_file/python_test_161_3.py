import queue
from sys import stdin, stdout

def test_case():
    n = int(stdin.readline().rstrip())
    pairs = set()

    bl, br = 0, 0
    for i in range(n):
        l, r = [int(x) for x in stdin.readline().rstrip().split()]
        pairs.add((l, r))
        if r - l > br - bl:
            bl, br = l, r

    q = queue.Queue()
    q.put((bl, br))

    while not q.empty():
        l, r = q.get()
        if l == r:
            print(l, r, l)
            continue
        for d in range(l + 1, r):
            if (l, d - 1) in pairs and (d + 1, r) in pairs:
                q.put((l, d - 1))
                q.put((d + 1, r))
                print(l, r, d)
                continue
        if (l, r - 1) in pairs:
            q.put((l, r - 1))
            print(l, r, r)
            continue
        if (l + 1, r) in pairs:
            q.put((l + 1, r))
            print(l, r, l)
            continue

if __name__ == "__main__":
    t = int(stdin.readline())
    for i in range(t):
        test_case()
