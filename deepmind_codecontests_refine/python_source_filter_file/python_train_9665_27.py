N=int(input())
A=[]
for _ in range(N):
    a=int(input())
    if a not in A:
        A.append(a)
    else:
        A.remove(a)
print(len(A))