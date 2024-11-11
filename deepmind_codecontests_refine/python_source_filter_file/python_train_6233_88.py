A = list(map(int, input().split()))
A.sort()

print("Yes" if A == [5,5,7] else "No")