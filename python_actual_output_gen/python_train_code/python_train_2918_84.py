a,b=map(int,input().split())
print(min(a,b),end=' ')
y=abs(a-b)
if(y%2==0):
    print(y//2)
else:
    print(y-1)