import sys
input = sys.stdin.readline

def standard_form(A):
    C = A[:]
    L = 60
    E = []
    ids = []
    for i in range(L):
        e = j0 = None
        mask = (1 << i)-1
        for j, a in enumerate(C):
            if (a >> i) & 1 and (a & mask) == 0:
                e = a
                j0 = j
                break
        else:
            continue
        ids.append(j0)
        for j, a in enumerate(C):
            if j0 == j:
                continue
            if (a >> i) & 1:
                C[j] ^= e
    return [C[e] for e in ids]


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = input()
    A = []
    B = []

    task = set([0])

    now = s[n-1]
    if now == "1":
        print(1)
        continue


    q = []
    win = "0"
    for i in range(n-1, -1, -1):
        if now == "0":
            if s[i] == "0":
                q.append(a[i])
            else:
                q = standard_form(q)
                task = task | set(q)
                task = set(standard_form(list(task)))
                q = [a[i]]
                now = "1"
        else:
            if s[i] == "1":
                q.append(a[i])
            else:
                q = standard_form(q)
                q = set(q) | task
                q = set(standard_form(list(q)))
                if task != task | q:
                    win = "1"
                    break

                q = [a[i]]
                now = "0"

    if now == "1":
        q = standard_form(q)
        q = set(q) | task
        q = standard_form(list(q))
        q = set(q)
        if task != task | q:
            win = "1"

    print(win)
