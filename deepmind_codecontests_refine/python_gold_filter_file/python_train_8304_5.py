h,n = map(int, input().split())
l = list(map(int, input().split()))
print("Yes" if h <= sum(l) else "No")