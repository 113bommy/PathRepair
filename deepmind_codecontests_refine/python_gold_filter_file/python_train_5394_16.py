N = int(input())
L = list(map(int, input().split()))
print("Yes" if 2 * max(L) < sum(L) else "No")