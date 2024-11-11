t = int(input())
for _ in range(t):
    n = int(input())
    
    s = set(map(int, input().split()))
    
    fl = 0
    for i in range(1, max(s)+1):
        new_s = set([el ^ i for el in s])
        if new_s == s:
            print(i)
            fl=1
            break
    if fl == 0:
        print(-1)