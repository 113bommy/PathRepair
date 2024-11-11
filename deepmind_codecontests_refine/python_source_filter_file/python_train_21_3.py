T = int(input())

for _ in range(T):
    n, left, right = map(int, input().split())
    l = [0]*n
    l[1] = 2*n-2
    
    for i in range(2, n):
        l[i] = l[i-1]-2
    
    l[-1] += 1
    left_n = -1
    right_n = -1
    acc = 0
    
    for i in range(1, n):
        if acc+1<=left:
            left_n = i
        
        acc += l[i]
        
        if right<=acc:
            right_n = i
            break
    
    #print(l)
    #print(left_n)
    #print(right_n)
    ans = []
    
    for i in range(left_n, right_n+1):
        now = []
        
        for j in range(l[i]):
            if j%2==0:
                now.append(i)
            else:
                if j==1:
                    now.append(i+1)
                else:
                    now.append(now[-2]+1)
        
        if i==right_n:
            now[-1] = 1
        
        ans += now
    
    sta = left-sum(l[:left_n])-1
    
    print(*ans[sta:sta+right-left+1])