n,k=map(int,input().split())
a=input()
a=[i for i in a]
for i in range(n):
    if k==0:
        break
    if i==0:
        if a[0]!='1':
            a[0]='1'
            k-=1
    else:
        if a[i]!='0':
            a[i]='0'
            k-=1
if n==1 and k>0:
    print('0')
else:
    for i in a:
        print(i,end='')