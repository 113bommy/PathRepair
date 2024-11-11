def cross(a,b):return a[0]*b[1] - a[1]*b[0]
def dif(a,b):return [x-y for x,y in zip(a,b)]

x = range(int(input()))
t = 1
P,Q = [],[]
for _ in x:P+=[[int(i) for i in input().split()]]
for i in x:Q+=[dif(P[i],P[i-1])]
for i in x:if cross(Q[i-1],Q[i]) < 0: t *= False
print(t)