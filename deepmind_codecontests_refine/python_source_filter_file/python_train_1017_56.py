n,k,s=map(int,input().split())
if s<=10**9:
    Ans=[s]*k+[s+1]*(n-k)
else:
    Ans=[s]*k+[1]*(n-k)
print(*Ans)