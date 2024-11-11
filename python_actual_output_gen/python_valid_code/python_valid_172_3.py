n=input().split()
n=int(n[0])
t=9999
r='YES'
for i in range(n):
    m=input()
    for j in m:
        if not j==m[0]:
            r='NO'
    if t==int(m[0]):
        r='NO'    
    t=m[0]
print(r)