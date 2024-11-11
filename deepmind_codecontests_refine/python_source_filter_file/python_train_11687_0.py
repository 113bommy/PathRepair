import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k, l = map(int, input().split())
    d = list(map(int, input().split()))
    safe = [0]
    
    for i in range(n):
        if d[i]+k<=l:
            safe.append(i+1)
        
    safe.append(n+1)
    ok = True
    
    for i in range(1, len(safe)):
        tide = k
        down = True
        
        for j in range(safe[i-1]+1, safe[i]-1):
            tide += -1 if down else 1
            
            if down:
                tide -= max(0, d[j]+tide-l)
            
            if tide<0 or d[j]+tide>l:
                ok = False
                break
        
            if tide==0:
                down = False
    
    if ok:
        print('Yes')
    else:
        print('No')