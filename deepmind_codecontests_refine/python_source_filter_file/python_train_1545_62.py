n=int(input())
a=[input()for i in range(n)]
m=int(input())
b=[input() for i in range(m)]
c=[a.count(a[i])-b.count(a[i]) for i in range(n)]
print(max(c))