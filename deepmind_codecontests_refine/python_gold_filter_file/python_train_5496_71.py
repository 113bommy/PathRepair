M=int(input())
#Get the number that needs to be handled
num=''
D,C=[],[]
for _ in range(M):
    D1,C1=map(int, input().split())
    D.append(D1)
    C.append(C1)
S = sum(d * c for d, c in zip(D, C))
print (sum(C)-1+(S-1)//9)