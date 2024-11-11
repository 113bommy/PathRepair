n = int(input())
A = list(map(int, input().split()))
B = sorted([a-i-1 for i, a in enumerate(A)])
m = B[n//2]
print(sum(abs(b-m) for b in B))