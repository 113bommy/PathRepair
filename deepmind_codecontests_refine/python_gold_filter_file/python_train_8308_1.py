#pdf見た
n = int(input())
q = [0]*n
for i in range(n):
    p = int(input())-1
    q[p] = i
    
s=f=0
c = set()
for i in range(1,n):
    if q[i]<q[i-1]:
        f=i-1
        c.add(f-s+1)
        s=i
if c==set():
    print(0)
else:
    print(n-max(c))