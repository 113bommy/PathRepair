n = int(input())
*a, = map(int, input().split())
print("YES" if n == len(set(a)) else "NO")
