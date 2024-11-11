def Respuesta(X,Y):
    X1 = list(set(X))
    Y1 = list(set(Y))
    if (len(X1)== 2 and len(Y1)==2):
        return abs((Y1[1]-Y1[0])*(X1[1]-X1[0]))
    else:
        return -1


n = int(input())
X = []
Y = []
for i in range (0,n):
    L = input()
    L =L.split()
    X.append(int(L[0]))
    Y.append(int(L[1]))

if n==1:
    print(-1)
else:
    print(Respuesta(X,Y))