k=int(input())
L=list(input())
L+=list(input())
L+=list(input())
L+=list(input())
L.sort()
c=True
if('.' in L):
    L=L[L.count('.'):]
for i in set(L):
    if(L.count(i)>k):
        c=False
        break 
if(c):
    print('YES')
else:
    print('NO')