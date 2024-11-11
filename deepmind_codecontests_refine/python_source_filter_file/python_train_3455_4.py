n,k=map(int,input().split())
l=list(input())

if k==0:
    print(*l,sep='')
elif n==1:
    print(0)
else:
    if l[0]!='1':
        #print("HI")
        l[0]='1'
        k-=1
    for i in range(1,n):
        print(k)
        if k>0 and int(l[i])>0:
            if l[i]!='0':
                l[i]='0'
                k-=1
    print(*l,sep='')
