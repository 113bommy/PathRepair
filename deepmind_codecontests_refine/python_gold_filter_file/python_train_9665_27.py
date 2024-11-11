N=int(input())
A=set()
for _ in range(N):
    a=int(input())
    if a not in A:
        A.add(a)
    else:
        A.remove(a)
print(len(A))