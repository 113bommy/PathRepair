n=int(input())
d={}
l=list(map(int,input().split()))
for i in l:
     if i in d:
          d[i]+=1
     else:
          d[i]=1
d=dict(sorted(d.items(),key=lambda x:x[1],reverse=True))
ans=0
for i in d:
     if d[i]>2 and i!=0:
          ans=-1
          break
     elif d[i]==2 and i!=0:
          ans+=1
print(ans)
