from collections import defaultdict

n = int(input())

for j in range(n):
    t = int(input())
    di = defaultdict(int)
    for k in range(t):
        s = input().strip()
        for i in s:
            di[i]+=1
    
    ans = sum([i%2 for i in di.values()])
    if ans==0:
        print('YES')
    else:
        print('NO')
        