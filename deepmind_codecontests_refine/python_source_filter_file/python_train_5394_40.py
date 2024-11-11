
N = int(input())
a = list(map(int, input().split()))

print("Yes" if max(a) > sum(a)-max(a) else "No")
