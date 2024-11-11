q,h,re,d = map(int,input().split())
n = int(input())
re = min(q*4, h*2,re)
print(min(re*n, n//2*d + (n%2)*re))