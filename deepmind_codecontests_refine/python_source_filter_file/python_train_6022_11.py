from bisect import bisect_left, bisect_right
N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
A.sort()
B.sort()
C.sort()
ans=0
for j in range(N):
    a=bisect_left(a, B[i])
    c=bisect_right(a, B[i])
    ans+=a*c
print(ans)
