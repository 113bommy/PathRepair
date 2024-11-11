s=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
C=[int(i) for i in A]
CC=[int(i) for i in A]
R=[]
X=[]
for k in range(len(A)):
    if A[k]!=B[k]:
        R.append(k)
if len(R)==2:
    CC[R[1]]=B[R[1]]
    C[R[0]]=B[R[0]]
    for k in range(len(A)):
        if (C.count(k)>1):
            C=CC
            break
else:
    for k in range(1,len(A)+1):
        if (A.count(k)==0):
            C[R[0]]=k
            break

print ((' ').join(map(str,C)))