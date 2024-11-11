N = int(input())
L = list(map(int,input().split()))
import bisect

L.sort()
ans = 0
 
for i in range(N-2):
  for j in range(i+1,N-1):
    ans += bisect.bisect_left(L,L[i]+L[j])
        
print(ans)