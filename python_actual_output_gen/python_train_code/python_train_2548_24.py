n = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
print(sum(A[n:n+n]))
