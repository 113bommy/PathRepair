from decimal import *
getcontext().prec=11

n=int(input())
precision=1e-13
def same(x,y):
    return abs(x-y)<precision
liste=[]
for test in range(n):
    x,y=map(int,input().split(" "))
    liste.append((x,y,test+1))
liste.sort(key=lambda element: (element[0],element[1]))

redundancy=False
for i in range(n-1):
    if liste[i][0]==liste[i+1][0]:
        redundancy=True
        index=i
        break

if not redundancy:
    for i in range(1,n-1):
        slope1=Decimal(liste[i][1]-liste[i-1][1])/Decimal((liste[i][0]-liste[i-1][0]))
        slope2=Decimal((liste[i][1]-liste[i+1][1]))/Decimal(liste[i][0]-liste[i+1][0])
        if not same(slope1,slope2):
            print("{} {} {}".format(liste[i-1][2],liste[i][2],liste[i+1][2]))
            visited=True
            break
else:
    i=index
    if 0<i:
        print("{} {} {}".format(liste[i-1][2],liste[i][2],liste[i+1][2]))
        visited=True
    else:
        while i<n:
            if liste[i][0]!=liste[index][0]:
                i-=1
                break
            i+=1
        print("{} {} {}".format(liste[i-1][2],liste[i][2],liste[i+1][2]))
        visited=True