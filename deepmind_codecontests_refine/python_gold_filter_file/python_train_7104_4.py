def solve(n0,n1,n2):
    if(n1==0):
        if(n0!=0):
            ans=[0]*(n0+1)
        else:
            ans=[1]*(n2+1)
    else:
        ans=[0]*(n0+1)+[1]*(n2+1)
        n1-=1
        i,a=0,[]
        while(i<n1):
            if(i%2==0):
                a=[1]+a
            else:
                a=[0]+a
            i+=1
        ans=a+ans
    for m in ans:
        print(m,end='')
    print()

t=1
t=int(input())
while(t>0):
    # rows, cols = (5, 5) 
    # arr = [[0 for i in range(cols)] for j in range(rows)] 
    n0,n1,n2 = [int(x) for x in input().split()]
    # n = int(input()) 
    solve(n0,n1,n2)
    t-=1