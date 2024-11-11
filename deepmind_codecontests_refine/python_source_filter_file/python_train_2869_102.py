N=int(input())
L=[]
for i in range(N):
    K=input()
    L.append(K)
for i in range(len(L)):
    if len(L[i])>10:
        print(L[i][0]+str(len(L[i]))+L[i][0])
    else:
        print(L[i])
