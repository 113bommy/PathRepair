def solve(n,k,hts):
    prefix = [0]*(n)
    for i in range(1,n-1):
        if hts[i-1]<hts[i] and hts[i]>hts[i+1]:
            prefix[i]=1
            
    for i in range(1,n):
        prefix[i]=prefix[i]+prefix[i-1]
    

    pieces,ans=0,200008
    for i in range(n):
        left = i
        right = (left+k)-1
        if right>=n:
            break
        
        p = prefix[right-1]-prefix[left]
        if p>pieces:
            pieces = p
            ans = left
    
    return (pieces+1),(ans+1)




tc = int(input())
for _ in range(tc):
    n,k = map(int,input().split())
    hts = list(map(int,input().split()))
    t,l = solve(n,k,hts)
    print(f'{t} {l}')