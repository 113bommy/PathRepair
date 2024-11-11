n=int(input())
arr=list(map(int,input().strip().split(' ')))
x=4.5*n-sum(arr)
if(x<=0):
    print(0)
else:
    arr.sort()
    i=n-1
    cnt=0
    while(x>0):
        x-=5-arr[i]
        if(arr[i]!=5):
            cnt+=1
        i-=1
        if(i<0):
            break
    print(cnt)
