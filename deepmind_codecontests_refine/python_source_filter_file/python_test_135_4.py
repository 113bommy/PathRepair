t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    lst=list(map(int,input().split()))
    lst.sort()
    jk=n-2*k
    lsts=lst[jk:n]
    sums=0
    for i in range(k):
        sums=sums+int(lsts[i]/lsts[2*k-i-1])
    sums=sums+sum(lst[:jk])
    print(sums)