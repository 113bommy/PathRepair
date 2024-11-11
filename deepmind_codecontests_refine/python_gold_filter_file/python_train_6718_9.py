Q=input#kitten
F,I,T=map(int,Q().split(" "))
A=[0]*I
X=range
for i in X(F):
    a=Q()
    for j in X(I):
        A[j] += a[j] == 'Y'
print(sum([x>=T for x in A ]))
