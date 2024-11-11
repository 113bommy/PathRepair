n = int(input())
x, y = map(int, input().split())
print("Black" if max(x-1, y-1) > max(n-x, -y) else "White")