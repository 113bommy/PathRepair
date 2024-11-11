n, t = map(int, input().split())
a = list(map(int, input().split()))
q = 0

for x in range(len(a)) :
    q += 86400 - a[x]
    if t == q :
        print(x + 1)
        break