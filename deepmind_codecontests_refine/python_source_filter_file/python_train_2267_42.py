x,n=map(int,input().split())
S=map(int, input().split())
K=(list(range(1,101)))
for i in S:
    K.remove(i)
L=[]
for i in K:
    L.append(abs(x-i))
m=min(L)
ind_m=L.index(m)
print(K[ind_m])