t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    found=0
    if len(a)>len(b):
        for j in range(len(a)):
            if a[j] in b:
                print('YES')
                print(1 ,a[j])
                found=1
                break
        if found==0:
            print('NO')
    else:
        for j in range(len(b)):
            if b[j] in a:
                print('YES')
                print(1 ,a[j])
                found=1
                break
        if found==0:
            print('NO')