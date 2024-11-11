n=int(input())
l=['o']*n
f1=f2=1
while f2<=n:
    l[f2-1]='O';f1,f2=f2,f1+f2
print(''.join(l))