n,a,b=map(int,input().split())
A=list(map(int,input().split()))
bl=0
w=0
k=1
c=0
ans=0
if(n%2!=0 and A[n//2]==2):
    c+=1
for i in range(0,n//2):
    if(A[i]!=2 and A[n-i-1]!=2 and A[i]!=A[n-i-1]):
        k=0
        break
    elif(A[i]==2 and A[n-i-1]!=2):
        if(A[n-i-1]==0):
            w+=1
        else:
            bl+=1
    elif(A[i]!=2 and A[n-i-1]==2):
        if(A[i]==0):
            w+=1
        else:
            bl+=1
    elif(A[i]==2 and A[n-i-1]==2):
        c+=2
if(k==0):
    print(-1)
else:
    ans+=w*a+bl*b+c*min(a,b)
    print(ans)