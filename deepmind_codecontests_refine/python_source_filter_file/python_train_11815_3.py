n,s=input().split()
n=int(n)
s=int(s)
d=list(map(int,input().split()))
s2=sum(d)
for i in range(0,n):
    temp1=s-(s2-d[i])
    temp2=s-(n-1)
    ans=max(temp1-1,1)+max(d[i]-temp2,0)
    print(ans,end=' ')
    
