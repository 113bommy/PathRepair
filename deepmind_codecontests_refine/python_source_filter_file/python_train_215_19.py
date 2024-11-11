import bisect

n,s=map(int,input().split())
A=list(map(int,input().split()))

A.sort()
r=bisect.bisect_left(A,s)
l=bisect.bisect_right(A,s)

#n//2個目がsになればよい
#sより小：r個
#sより大:n-l個
#s:l-r個

ANS=float("inf")
ANS2=float("inf")

if r>=n//2:
    
    ANS=(r-n//2)*s-sum(A[n//2:r])

if n-l>=n//2:
    ANS2=sum(A[l:n//2+1])-(n//2+1-l)*s

x=min(ANS,ANS2)

if x!=float("inf"):
    print(x)
else:
    print(0)


