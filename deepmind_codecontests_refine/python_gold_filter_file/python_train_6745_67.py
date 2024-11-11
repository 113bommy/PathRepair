A=input()
c=0
B=A[::-1]
for i in range(len(A)):
    if A[i]!=B[i]:
        c+=1
print(c//2)