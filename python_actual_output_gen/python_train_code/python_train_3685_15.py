T = int(input())
for t in range(T):
    N,M=map(int,input().split())
    lst=list(map(int,input().split()))
    if M<N:
        print(-1)
    else:
        tot=2*sum(lst)
        if N!=M:
            var1=lst.index(min(lst))
            temp=lst[var1]
            lst[var1]=10000
            var2=lst.index(min(lst))
            tot+=(temp+lst[var2])*(M-N)
        print(tot)
        for i in range(N):
            if i+1<N:
                print("{} {}".format(i+1,i+2))
            else:
                print("{} {}".format(i+1,1))
        if N!=M:
            for i in range(M-N):
                print("{} {}".format(var1+1,var2+1))
