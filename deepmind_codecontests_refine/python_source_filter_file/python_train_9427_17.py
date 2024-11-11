n, k = map(int, input().split())
lis = [len(input()) for _ in range(n)]
lis.sort()
p = len(input())
import bisect 
r = bisect.bisect(lis, p)
l = bisect.bisect_left(lis, p)+1
print(l + 5*(l//k), r + 5*(r//k))