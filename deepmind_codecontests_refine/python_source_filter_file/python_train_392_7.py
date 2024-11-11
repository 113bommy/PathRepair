n=int(input())
a=[int(input()) for _ in range(n)]
as=sorted(a)
m=as[-1]
for i in range(n):
    print(m if m!=a[i] else a[-2])