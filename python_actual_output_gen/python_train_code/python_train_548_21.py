n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for j in range(m)]
l=list(set(s))
print(l)
print(max(0,max(s.count(l[i])-t.count(l[i]) for i in range(len(l)))))