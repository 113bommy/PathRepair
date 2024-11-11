q, h, s, d = map(int, input().split())
n = int(input())

s = min(q*4, h*2, s)

print(s*n if d>s*2 else d*(n//2)+s*(n%2))


