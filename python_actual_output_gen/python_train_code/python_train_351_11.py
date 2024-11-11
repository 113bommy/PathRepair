def function(arr):
    mx,t=0,0
    arr=arr+[90]
    for m in arr:
        if m-t>0:
            return mx+15
        mx=mx+m-t
        t=m
    return mx
if __name__=='__main__':
    n=int(input())
    arr=list(map(int,input().split()))
    print(function(arr))    