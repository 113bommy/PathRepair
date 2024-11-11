for _ in range(int(input())):
    n = int(input())
    w = list(map(int,input().split()))
    dic = [0]*(n+1)
    for i in w:
        dic[i]+=1
    ans = 0
    for s in range(2,max(w)*2):
        cur = 0
        for i in range(1,(s+1)//2):
            if s-i<=n: cur+=min(dic[i],dic[s-i])
        if s%2==0: cur+=dic[s//2]//2
        ans = max(ans,cur)
    print(ans)