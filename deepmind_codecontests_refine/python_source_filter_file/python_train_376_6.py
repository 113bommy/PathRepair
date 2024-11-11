a=int(input())
b=int(input())
n=0
m=0
if a>b:
    n=(a-b)/2
    m=(a-b)-n
else:
    n=int((b-a)/2)
    m=(b-a)-n
print(int((n*(n+1))/2+(m*(m+1))/2))