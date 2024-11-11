def solve(n,a,b):
    for i in range(n):
        if(a[i]>b[i]):
            return -1
    ans=0
    for j in range(20):
        cr=chr(97+j)
        arr=[]
        x='z'
        for i in range(n):
            if(a[i]==cr and b[i]>cr):
                x=min(b[i],x)
                arr.append(i)
                
        if(len(arr)!=0):
            ans+=1
            for k in arr:
                a[k]=x

    return ans


for _ in range(int(input())):
    n=int(input())
    a=list(input())
    b=list(input())
    print(solve(n,a,b))