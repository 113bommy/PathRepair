cnt = lambda s, x: s.count(x)
ii = lambda: int(input())
si = lambda: input()
f = lambda: map(int, input().split())
il = lambda: list(map(int, input().split()))
dgl = lambda: list(map(int,input()))
n=ii()
l1=[max(f())]
for _ in range(n-1):
    a,b=f()
    if max(a,b)<=l1[-1]:
        l1.append(max(a, b))
    elif min(a,b)<=l1[-1]:
        l1.append(min(a, b))
    else:
        print('NO')
        exit(0)
print('YES')
