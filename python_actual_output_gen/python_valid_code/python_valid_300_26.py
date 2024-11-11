a,b,n = map(int,input().split())
m = 0
x = n
if b < n:x = b-1
print((a*x//b))