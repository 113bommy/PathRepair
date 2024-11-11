n=int(input())
a=list(map(int,input().split()))
d={}
m=int(input())
v,p=0,0
q=list(map(int,input().split()))
count=1
for i in range(n):
    d[a[i]]=count
    count+=1

for j in range(len(q)):
    v=v+d[q[j]]
    p=p+(n+1-d[i])
print(v,p)
