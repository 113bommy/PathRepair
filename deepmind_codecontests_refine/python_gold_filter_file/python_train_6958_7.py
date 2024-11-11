q,h,s,d = map(int,input().split())	
s=min(4*q,2*h,s)
d=min(2*s,d)
n=int(input())
print((n//2)*d+(n%2)*s)

