for t in range(1):
    n=int(input())
    arr=list(map(int,input().split()))
    arr.sort()
    ans=[0]*n
    i=0
    while len(arr)>0:
        ele=arr.pop(0)
        if i%2==0:
            pos=i//2
            ans[pos]=ele
        else:
            pos=n-1-(i//2)
            ans[pos]=ele
        i+=1
    print(ans)