n, m = map(int, input().split())
a, b = input().split(), input().split()
print("YES" if a[0] == "1" and a[m - 1] == "1" or (b[m - 1] == "1" and any(i + j == '11' for i, j in zip(a[m:], b[m:]))) else "NO")