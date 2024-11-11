n=int(input())
A=set()
for i in range(n):
    a=input()
    if a in A:
        A.remove(a)
    else:
        A.append(a)
print(len(A))