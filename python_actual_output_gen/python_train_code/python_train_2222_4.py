n,m=map(int,input().split())
A=[]
B=[]
for i in range(m):
    l,r = map(int,input().split())

    A.append(l)
    B.append(r)
print(min(B)-max(A)+1)
