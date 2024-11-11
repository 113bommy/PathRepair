def ceil(x,y):
    return x//y+(not( not x%y))
n=int(input())
a,b=1,1
for i in range(n):
    t,s = map(int,input().split())
    i = max( ceil(a/t), ceil(b/s) )
    a=t*i;b=s*i
print(a+b)