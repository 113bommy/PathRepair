H, N = map(int,input().split())
An = list(map(int,input().split()))
print("Yes" if H <= sum(An) else "No")