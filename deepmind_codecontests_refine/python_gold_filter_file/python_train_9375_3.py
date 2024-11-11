x1,x2,x3,x4,x5,x6 = map(int,(input().split()))
t = input()
x=x1


L=[x1,x2,x3,x4,x5,x6]
n= len(t)
T=[]
M=[]
for i in range(n):
    T.append(t[:1])
    t=t[1:]



for i in T:
    if i is "S":
        L = [L[4],L[0],L[2],L[3],L[5],L[1]]
    elif i is "E":
        L = [L[3], L[1], L[0], L[5], L[4], L[2]]
    elif i is "N":
        L = [L[1], L[5], L[2], L[3], L[0], L[4]]
    else:
        L = [L[2], L[1], L[5], L[0], L[4], L[3]]



print(L[0])