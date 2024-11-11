q = int(input())
def slide(s,l):
    ans = len(l)
    for i in range(len(s)-len(l) + 1):
        cnt = 0
        for j in range(len(l)):
            if s[i+j] != l[j]:
                cnt += 1
        ans = min(ans,cnt)
    return ans
            
        
for i in range(q):
    n,k = map(int,input().split())
    p = input()
    L = []
    s = 'RGB'*2000
    for i in range(3):
        L.append(s[i:i + k])
    ans = k
    print(L) 
    for i in range(3):
        ans = min(slide(p,L[i]),ans)
    print(ans)
    
