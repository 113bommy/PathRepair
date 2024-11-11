from collections import *

n = int(input())
a = list(map(int, input().split()))
cnt = Counter(a)
ans = [[-1]*n for _ in range(n)]
q = deque([])

if n%2==0:
    for k, v in cnt.items():
        if v%4!=0:
            print('NO')
            exit()
        
        for _ in range(v//4):
            q.append(k)
        
    for i in range(n//2):
        for j in range(n//2):
            v = q.popleft()
            ans[i][j] = v
            ans[n-1-i][j] = v
            ans[i][n-1-j] = v
            ans[n-1-i][n-1-j] = v
else:
    flag = False
    
    for k, v in cnt.items():
        if v%2==1:
            if flag:
                print('NO')
                exit()
            
            flag = True
            ans[n//2][n//2] = k
            cnt[k] -= 1

        for _ in range(v//4):
            if len(q)==(n//2)**2:
                break
                
            q.append(k)
            cnt[k] -= 4
            
    if len(q)<(n//2)**2:
        print('NO')
        exit()
        
    for k, v in cnt.items():
        for _ in range(v//2):
            q.append(k)
    
    for i in range(n//2):
        for j in range(n//2):
            v = q.popleft()
            ans[i][j] = v
            ans[n-1-i][j] = v
            ans[i][n-1-j] = v
            ans[n-1-i][n-1-j] = v
    
    for i in range(n//2):
        v = q.popleft()
        ans[i][n//2] = v
        ans[n-1-i][n//2] = v
    
    for i in range(n//2):
        v = q.popleft()
        ans[n//2][j] = v
        ans[n//2][n-1-j] = v

print('YES')

for ans_i in ans:
    print(*ans_i)