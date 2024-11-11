n=int(input())
A=[]
for i in range (0,n):
    x,y=map(int,input().split())
    A.append([x,y])
L=[]
for i in range (0,n):
    l=A[i][1]+A[i][0]
    L.append(l)
print(max(L))