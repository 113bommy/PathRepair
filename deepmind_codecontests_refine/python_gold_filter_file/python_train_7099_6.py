def solution(arr,n,i):
    temp=i 
    remp=arr[i]
    cnt=1 

    while remp!=i:
        temp,remp=remp,arr[remp]
        cnt+=1
    return cnt


q=int(input())
for _ in range(q):

    n=int(input())
    arr=list(map(int,input().strip().split()))
    for i in range(n):
        arr[i]-=1 
    ans=[]

    for i in range(n):
        ans.append(solution(arr,n,i))
    print(*ans)
