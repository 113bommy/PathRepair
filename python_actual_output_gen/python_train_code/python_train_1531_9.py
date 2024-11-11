n=int(input())
arr=list(map(int,input().split()))
a=arr
xx=list(map(int,input().split()))
xx.sort()
x=xx[0]
y=xx[1]
if x==y:
    print(0)
else:
    # print(arr[x-1:y-1])
    aa=sum(arr[x-1:y-1])
    # bb=sum(a[n+x-1:n+y-1])
    bb= sum (a[y-1:]+a[:x])
    print(min(aa,bb))
