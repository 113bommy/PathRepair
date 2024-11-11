t = int(input())
for _ in range(t):
    n,k,d = map(int,input().split())
    l1 = list(map(int,input().split()))
    ans=n
    for j in range(n-d+1):
        ans = min(n,len(set(l1[j:j+d])))
        #print(l1[j:j+d])
    print(ans)
