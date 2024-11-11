N = int(input())
A = list(map(int, input().split()))
print("Yes" if max(A) < sum(A)-max(A) else "No")