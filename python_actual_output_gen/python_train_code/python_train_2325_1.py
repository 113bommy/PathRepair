Q=input
F,I,T=map(int,Q().split(" "))
A=[0]*F
X=range
for i in X(F):
    a=Q()
    for j in X(I):
        A[i] += a[j] == 'Y'
print(sum([x>=T for x in A ]))
