a = input()
b = input()
p = list(map(int,input().split()))

n = len(p)
h = [0]*n
for i in range(n):
    p[i]-=1
    h[p[i]] = i

def check(s1,s2,g):
    m1 = len(s1)
    m2 = len(s2)
    j = 0
    i = 0
      
    while j<m1 and i<m2: 
        if s1[j] == s2[i] and h[i]>g:     
            j = j+1    
        i = i + 1
    return j==m1

l = 0
r = n-1

while l<r:
    md = (l+r+1)//2
    # print(md,p[md],h[p[md]])
    if check(b,a,h[p[md]]):
        # print(md,p[md],h[p[md]])
        l = md
    else:
        r = md-1

print(l+1)