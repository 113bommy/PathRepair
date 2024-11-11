q, h, s, d = map(int, input().split())
n = int(input())

ans = n//2*min(8*q, 4*h, 2*s, d) + min(4*q, 2*h, s)*(n%2!=0)
print(ans)
