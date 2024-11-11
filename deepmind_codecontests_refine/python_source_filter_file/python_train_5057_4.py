n,k=map(int,input().split())
l=[]
ans=-1
for i in range(1,n+1):
    if i*i>n:
        break
    if n%i==0:
        k-=1
        l.append(i)
    if k==0:
        ans=i
        break
if ans!=-1:
    print(ans)
else:
    if l[-1]*l[-1]==n:
        if k>len(l)-1:
            print(ans)
        else:
            print(n//l[len(l)-k])
    else:
        if k>len(l):
            print(ans)
        else:
            print(n//l[len(l)-k])

        
    
