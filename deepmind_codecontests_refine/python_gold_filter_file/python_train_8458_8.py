t=int(input())
for i in range(t):
    n=int(input())
    L1=[]
    L1 = input().split()
    for j in range(len(L1)):
        L1[j] = int(L1[j])
    L2=[]
    for j in range(2*n):
        if(L1[j] not in L2):
            L2.append(L1[j])
    for j in range(n):
        print(L2[j],end=" ")