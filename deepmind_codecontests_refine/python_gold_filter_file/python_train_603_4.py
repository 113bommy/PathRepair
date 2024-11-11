from collections import Counter
N,M=map(int,input().split())
A=list(map(int,input().split()))
A.insert(0,0)
cnt = Counter()
for i in range(N): A[i+1] += A[i]
for i in range(N+1): cnt[A[i]%M] += 1
print(sum(n*(n-1)//2 for n in cnt.values()))
