from math import sqrt
def is_simple(a):
    for i in range(2,int(sqrt(a))+1):
        if a%i==0:
            return False
    else:
        return True
    
n, k = map(int, input().split())
q=[]
w=0
for i in range(2,n//2+3):
    if is_simple(i):
        q.append(i)
for i in range(len(q)-1):
    if is_simple(q[i]+q[i+1]+1) and q[i]+q[i+1]+1<=n:
        w+=1
if w<k:
    print('NO')
else:
    print('YES')