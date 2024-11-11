t = int(input())

for i in range(t):
    n = int(input())
    a = []
    b = []
    for i in range(n):
        t1, t2 = map(int, input().split())
        a.append(t1)
        b.append(t2)
    if n==1 and max(a)-min(b)<0:
        print(0)
        continue
    print(max(a)-min(b))