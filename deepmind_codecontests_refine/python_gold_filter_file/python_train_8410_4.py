import sys
n, k = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a)
l = []

def check(b) :
    r1 = [x % b for x in a]
    r1.sort()
    s1 = sum(r1)
    
    mn = 1e9
    s2 = 0
    for i in range(n):
        s2 += r1[i]
        mn = min(max(s2, (n-1-i)*b - (s1-s2)), mn)
        
    if mn <= k :
        print(int(b))
        sys.exit(0)
        

for p in range(1,int((s+1)**0.5+1)) :
    if s % p != 0:
        continue
    b = s // p
    l.append(p)
    check(b)
l.reverse()

for b in l:
    check(b)
        
    
