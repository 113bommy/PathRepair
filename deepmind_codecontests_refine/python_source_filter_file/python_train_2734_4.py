def remove(aa):
    n=len(aa)
    l=aa[0]
    for i in range(0,n):
        if abs(aa[i]-aa[0])>1:
            return 'NO'
        l=aa[i]
    return 'YES'
t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    aa=sorted(a)
    print(remove(aa))