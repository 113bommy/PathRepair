n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for i in range(m)]
lis=set(s)
print(max(0,max([s.count(l)-t.count(l) for l in lis]))