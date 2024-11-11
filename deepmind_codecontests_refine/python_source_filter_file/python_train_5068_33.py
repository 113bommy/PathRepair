n,b=map(int,input().split())
a=list(map(int,input().split()))
s=0
ans=[]
answ=0
for i in range(n-1):
    if a[i]%2:
        s+=1
    else:
        s-=1
    if s==0:
        ans.append(a[i+1]-a[i])
ans.sort()
for i in ans:
    b-=i
    if b>0:
        answ+=1
    else:
        break
print(answ)
