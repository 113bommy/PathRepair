n=int(input())
male=[0]*400
female=[0]*400
for _ in range(n):
    s=input().split()
    a=int(s[1])
    b=int(s[2])
    if s[0]=='M':
        male[a]+=1
        male[b+1]-=1
    else:
        female[a]+=1
        female[b+1]-=1
ans=0
t1=0
t2=0
for i in range(400):
    t1+=male[i]
    t2+=female[i]
    ans=max(ans,min(t1,t2))
print(ans)
