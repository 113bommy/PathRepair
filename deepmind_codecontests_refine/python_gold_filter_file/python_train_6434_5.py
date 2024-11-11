n,m=map(int,input().split())
A=[]
B=[]
for i in range(m):
    l,r = map(int,input().split())

    A.append(l)
    B.append(r)
print(max(0,min(B)-max(A)+1))
