import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    NG=max(A)-1
    OK=max(A)*2

    while OK>NG+1:
        mid=(OK+NG)//2
        MAX=(1<<(mid+1))-1

        DP=MAX

        for i in range(n):
            DP=(DP|(DP<<A[i])|(DP>>A[i]))&MAX

        if DP!=0:
            OK=mid
        else:
            NG=mid
    print(OK)
                    

    

    
        

    

    
