N=int(input())
S=input()
A=[]
a=S.count(".")
A.append(a)
for i in range(N):
    if S[0]=="#":
        a=a+1
    else:
        a=a-1
    A.append(a)
print(min(A))