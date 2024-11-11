n=int(input())
arr=list(map(int,input().split()))
arr.sort()
if n==1:
    if arr[0]==0:
        print('YES')
    else:
        print('NO')
else:
    t=0
    for i in range(2):
        if arr[i]==0:
            t+=1
        if t==2 or t==0:
            print('NO')
        else:
            print('YES')