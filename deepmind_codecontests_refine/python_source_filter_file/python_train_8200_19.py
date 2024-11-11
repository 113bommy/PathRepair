n = int(input())
*a, = map(int, input().split())
print("Yes" if n == len(set(a)) else "No")
