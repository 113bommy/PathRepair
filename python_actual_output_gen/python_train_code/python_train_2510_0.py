def func(n,a):
    d=a[1]-a[0]
    for i in range(2,n):
        if a[i]-a[i-1]!=d:
            return(a[-1])
    return a[-1]+d

n=int(input())   
a=list(map(int,input().split()))
func(n,a)
        