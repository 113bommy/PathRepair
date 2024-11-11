N=int(input())
B=set()

for i in range(N):
    a=int(input())
    if a in B:
        B.remove(a)
    else:
        B.add(a)
print(len(B))