q = int(input())
for _ in range(q):
    n = [0 for _ in range(int(input()))]
    for i in list(map(int, input().split())):
        n[i - 1] += 1
    n.sort(reverse=True)
    S = i = n.pop(0)
    while i > 0 and len(n) > 0:
        i -= 1
        i = min(i, n.pop(0))
        S += i
    print(S)
