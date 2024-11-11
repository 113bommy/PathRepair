from sys import stdin
from itertools import combinations
N,K = [int(x) for x in stdin.readline().rstrip().split()]
A = [int(x) for x in stdin.readline().rstrip().split()]
ans = 10**18
for i in combinations(range(1,N),K-1):
    tallest = A[0]
    tmp = 0
    for j in range(1,N):
        if j in i:
            if tallest >= A[j]:
                tmp += (tallest - A[j] + 1)
                tallest = (tallest + 1)
            else:
                tallest = max(tallest,A[j])
        else:
            tallest = max(tallest,A[j])
    ans = min(ans,tmp)
print(ans)