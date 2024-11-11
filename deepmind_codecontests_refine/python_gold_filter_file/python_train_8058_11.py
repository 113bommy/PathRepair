n,m = map(int,input().split())
a = input().split()
b = set()
for i in range(n):
    b.add(a[n-i-1])
    a[n-i-1] = len(b)
for j in range(m):
    c=int(input())
    print(a[c-1])
