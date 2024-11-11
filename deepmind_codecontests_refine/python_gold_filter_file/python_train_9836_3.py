s=0
l=[]
l1=[]
l2=[]
n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    l.append(a)
    s+=a
    l1.append(b)
    l2.append([a,b])
l1.sort()
ma1=l1[-1]
ma2=l1[-2]
ans=[]
for i in range(n):
    w=s-l[i]
    if(l2[i][1]==ma1):
        h=ma2
    else:
        h=ma1
    ans.append(w*h)
print(*ans)
