a=int(input())
b=int(input())
d=abs(a-b)
n=d//2
s=n*(n+1)
if(n%2!=0):
    s+=n+1
print(s)