n,m=map(int,input().split())
l=list(map(int,input().split()))
rem=[]
ans=0
for i in l:
    rem.append(i%10)
    ans=ans+i//10
    print(ans)
rem.sort()
i=n-1
while(i>=0 and m>0):
    if(rem[i]!=0):
        sm=10-(rem[i])
        if(m>=sm):
            m=m-sm
            rem[i]=0
            ans=ans+1
    print(ans)
    i=i-1
print(min(ans+m//10,n*10))








