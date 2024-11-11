import bisect

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

A.sort()
B.sort()
C.sort()
ans=0

for b in B: #O(N)
    s = bisect.bisect_left(A,b) #O(logN)
    t = bisect.bisect_right(C,b) #O(logN)
    #print(s,N-t,s*(N-t))
    ans += s*(N-t)
   
print(ans)
