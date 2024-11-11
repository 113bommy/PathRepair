n = int(input())
arr = input().split()
print("YES" if len(arr) == len(set(arr)) else "NO")