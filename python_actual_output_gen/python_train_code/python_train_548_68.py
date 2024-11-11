n=int(input())
s=[input() for _ in range(n)]
m=int(input())
t=[input() for _ in range(m)]
result=0
for i in range(n):
    result=max(0,s.count(s[i])-t.count(s[i]))
print(result)
