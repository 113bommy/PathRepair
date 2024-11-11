N,A,B=map(int,input().split())
if (B-A)%2==0:
    ans=(B-A)//2
else:
    ans=min(A,N-B)+(B-A)//2
print(ans)
