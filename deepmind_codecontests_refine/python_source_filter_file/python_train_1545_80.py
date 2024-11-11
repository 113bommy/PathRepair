n=int(input())
b=[input() for i in range(n)]
m=int(input())
r=[input() for i in range(m)]
ans=[]
for i in set(b):
    ans.append(b.count(i)-r.count(i))
print(max(ans))