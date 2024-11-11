n, l, r = map(int, input().split())
a=1
mn=0
mx= 0
for i in range(r):
    x= 2**i
    if i<l:
        mn= mn+x
    if i<r:
        mx= mx+x

for t1 in range(n-l):
    mn= mn+1
    
for t2 in range(n-r):
    mx= mx+x
    
print(mx, mn)