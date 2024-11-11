import math
def quck_sort(lst,start,end):
    if start>= end:
        return
    left = start
    right = end
    mid= lst[left]
    while left <right:
        while left < right and lst[right]<=mid:
            right-=1
        lst[left]=lst[right]
        while left <right and lst[left]> mid:
            left+=1
        lst[right]=lst[left]
    lst[left]=mid

    quck_sort(lst,start,left-1)
    quck_sort(lst,left+1,end)

    
def solve(n,L):
    ans=0
    quck_sort(L,0,len(L)-1)
    #print(L)

    for i in range(0,n):
        ans +=math.floor(L[n-1+i]/L[i])
        #print(ans)
    for i in range(2*n,len(L)-1):
        ans+=L[i]
    
    print(ans)      
    
for _ in range(int(input())):
    nk = list(map(int,input().split(" ")))
    n=nk[0]
    k=nk[1]
    L=list(map(int,input().split(" ")))
    solve(k,L)