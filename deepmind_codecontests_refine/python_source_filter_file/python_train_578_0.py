N = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
a=set()
b=set()
for i in range (N[1]-1,N[2]):
    a.add(A[i])
    b.add(B[i])
flag=True
for i in range (0,N[1]-1):
    if A[i]!=B[i]:
        flag=False
for i in range (N[2]-1,N[0]):
    if A[i]!=B[i]:
        flag=False
if a!=b:
    flag=False
if flag==True:
    print("TRUTH")
else:
    print ("LIE")
