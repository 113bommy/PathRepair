a, b, c = map(int, input().split())
print("YES" if any((a*i)%5==c for i in range(1, b+1)) else "NO")
