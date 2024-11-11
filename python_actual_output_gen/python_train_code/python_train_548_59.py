n=int(input())
s=[input() for i in range(n)]
m=int(input())
t=[input() for j in range(m)]
l=list(set(s))

result=max(s.count(i)-t.count(i) for i in l)

print(result)