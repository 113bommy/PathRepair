T = int(input())
from collections import Counter

for _ in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    
    for i in range(2,1001):
        b = []
        for j in range(2*n):
            b.append(a[j] % i)
            
        c = Counter(b)
        
        aa = 0
        for j in range((i-1)//2):
            aa += abs(c[j-1]-c[i-1-j])
        
        if i%2 == 0:
            aa += a[n//2] % 2
        aa += a[0] % 2
            
        if aa <= 2:
            gc = i
            break
            
    x = [[] for _ in range(gc)]
    
    for i in range(2*n):
        x[a[i]%gc].append(i)
    
    ans = []
    for i in range((gc-1)//2):
        for j in range(min(len(x[i+1]),len(x[gc-1-i]))):
            ans.append((x[i][j],x[gc-1-i][j]))
            
    if gc%2 == 0:
        for i in range(len(x[gc//2])//2):
            ans.append((x[gc//2][2*i],x[gc//2][2*i+1]))
            
    for i in range(len(x[0])//2):
        ans.append((x[0][2*i],x[0][2*i+1]))
        
    for i in range(n-1):
        print(*ans[i])