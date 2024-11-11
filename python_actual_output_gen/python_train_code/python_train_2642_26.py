l,r=map(int,input().split())
lim=(r-l+1)//2
print('YES')
a=1
for i in range(lim):
    print(a,a+1)
    a+=2