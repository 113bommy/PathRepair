A=input()
c=0
B=A[::-1]
for i in range(len(A)):
    if A[i]!=B[i]:
        cnt+=1
print(cnt//2)