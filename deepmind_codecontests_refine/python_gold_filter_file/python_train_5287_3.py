from collections import Counter

n=int(input())
a=list(map(int,input().split()))

q1=[]
q2=[]

for i in range(n):
  q1.append(i+a[i])
  q2.append(i-a[i])

c2=Counter(q2)

ans=0
for i in q1:
  ans+=c2[i]

print(ans)