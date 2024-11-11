t=int(input())
while t>0:
    k=int(input())
    arr=list(map(int,input().split()))
    f=0
    for i in range(k-1):
        if(arr[i+1]-arr[i]>=2):
            print('YES')
            print(i+1,i+2)
            f=1
            break
    if f==0:
        print('NO')
    t=t-1