n = int(input())
arr = input().split()
print("Yes" if len(arr) == len(set(arr)) else "No")