
T = int(input())
for t in range(T):

    n, a, b = map(int, input().split())
    l = list(map(int, list(input())))

    if b>=0:
        ans = a*n + b*n
    if b<0:
        cnt=0
        pre = l[0]
        for i in range(1, n):
            if pre!=l[i]:
                cnt+=1
            pre = l[i]
        cnt+=1
        print(cnt)
        k = cnt//2+1
        print(k)
        ans = a*n+b*k
        
    print(ans)
            
    
    