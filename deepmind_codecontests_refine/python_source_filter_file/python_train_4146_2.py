n=int(input())
a=[int(i) for i in input().split()]
d={}
for i in a:
    if i in d:
        d[i]+=1
    else:
        d[i]=1
p=max(a)*2
chk=[pow(2,i) for i in range(1,32) if pow(2,i)<=p]
ans=0
for i in a[::-1]:
    if d[i]>0:
        d[i]-=1
        for j in chk[::-1]:
            if j-i in d and d[j-i]>0:
                d[j-i]-=1
                ans+=1
                break
print(ans)