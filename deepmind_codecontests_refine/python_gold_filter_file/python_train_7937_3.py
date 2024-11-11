for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    l=-1
    case=0
    sm=0
    ans=0
    for i in range(n):
        if arr[i]!=i+1 and l==-1:
            l=i
        if l!=-1:
            sm+=arr[i]
        if arr[i]==i+1 and l!=-1:
            case=1
        if l!=-1:
            t1=((i+1)*(i+2))//2
            t2=(l*(l+1))//2
            if t1-t2==sm:
                ans+=1+case
                case=0
                l=-1
                sm=0
    print(min(ans,2))