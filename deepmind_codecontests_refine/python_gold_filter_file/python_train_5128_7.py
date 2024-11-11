N,k=map(int,input().split())
a=list(map(int,input().split()))

if k%2==0:
    def cond(n):
        res=0
        L=0
        for i in range(N):
            if a[i]>n:
                res+=(L+1)//2
                L=0
            else:
                L+=1
        res+=L//2
        if res>=k//2:
            return True

        res=0
        L=0
        for i in range(N-1,-1,-1):
            if a[i]>n:
                res+=(L+1)//2
                L=0
            else:
                L+=1
        res+=L//2
        if res>=k//2:
            return True

        return False

    start=0
    end=10**9
    while end-start>1:
        test=(end+start)//2
        if cond(test):
            end=test
        else:
            start=test
    print(end)
else:
    def cond(n):
        res=0
        L=0
        for i in range(N):
            if a[i]>n:
                res+=(L+1)//2
                L=0
            else:
                L+=1
        res+=(L+1)//2
        if res>=k//2+1:
            return True

        res=0
        L=0
        for i in range(N-2,-1,-1):
            if a[i]>n:
                res+=(L+1)//2
                L=0
            else:
                L+=1
        res+=L//2
        if res>=k//2:
            return True

        return False
    start=0
    end=10**9
    while end-start>1:
        test=(end+start)//2
        if cond(test):
            end=test
        else:
            start=test
    print(end)