n=int(input("n"))
A=[]
for i in range (0,n):
    x,y=map(int,input("x,y").split())
    A.append([x,y])
L=[]
for i in range (0,n):
    l=A[i][1]+A[i][0]
    L.append(l)
print(max(L))