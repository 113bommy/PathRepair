from collections import defaultdict

def solve():
    N, K = map(int, input().split())
    D = [int(k) for k in input().split()]
    
    d = defaultdict(int)
    
    ans = 0
    
    for x in D:
        if x % K == 0:
            ans += 1
            continue
        
        d[x % K] += 1
        
    Keys = set(d.keys())
    ans = (ans//2)*2

    for x in Keys:
        if x == K-x:
            ans += d[x]
            del d[x]
            
        elif K-x in d:
            ans += min(d[K-x], d[x])*2
            del d[x]
            
    print (ans)
    
if __name__ == "__main__":  
    solve()