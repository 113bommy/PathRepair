l, r=map(int, input().split())
loop=(r-l+1)//2
print('YES')
for i in range(loop):
    print(l,l+1)
    l+=1
