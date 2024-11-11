N=int(input())
A=set()
for i in range(N):
    a=int(input())
    if a in A:
        A.remove(a)
    else:
        A.add(a)
print(len(A))