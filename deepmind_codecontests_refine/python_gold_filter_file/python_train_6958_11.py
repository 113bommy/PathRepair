q,h,s,d = map(int,input().split())
n = int(input())

a = min(q*4,h*2,s)
print(min(a*n, d*(n//2)+a*(n%2)))
