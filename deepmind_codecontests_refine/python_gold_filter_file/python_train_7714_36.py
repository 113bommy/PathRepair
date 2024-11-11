l,r=map(int,input().split())
lim=(r-l+1)//2
print('YES')
for i in range(lim):
    print(l,l+1)
    l+=2