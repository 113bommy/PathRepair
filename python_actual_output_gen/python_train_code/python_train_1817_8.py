n = int(input())
ft = input()
r = ft.count('R')
l = ft.count('L')
if r==0:
    t = ft.index('L')
    for i in range(t,n-1):
        if ft[i+1]=='.':
            s=i+1
            break
    print(s,t+1)
elif l==0:
    s = ft.index('R')
    for i in range(s,n-1):
        if ft[i+1]=='.':
            t=i+1
            break
    print(s+1,t)
else:
    r = ft.index('R')
    l = ft.index('L')
    print(r+1,l+1)