x, y = map(int, input().split())
n = int(input())
z = [x, y, y - x, -x, -y, x - y]
print(z[(n) % 6] % (10**9 + 7))