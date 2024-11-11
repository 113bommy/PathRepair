N=int(input())
B=[]

for i in range(N):
    a=int(input())
    if a in B:
        B.remove(a)
    else:
        B.append(a)
print(len(B))