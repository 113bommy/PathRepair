H, N = map(int, input().split())
A = map(int, input().split())
print("Yes" if H <= sum(A) else "No")