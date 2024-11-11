n=int(input())
A=tuple(map(int,input().split()))
B=tuple(map(int,input().split()))
C=tuple(map(int,input().split()))

from collections import deque

d = deque([B])
USEDLIST=[[0 for i in range(n+1)]for j in range(n+1)]
USEDLIST[B[0]][B[1]]=1

def check(x,y):
    if x==A[0] or y==A[1]:
        return 0
    if abs(x-A[0])==abs(y-A[1]):
        return 0
    else:
        return 1

while d:
    search=d.pop()
    #print(search)
    searchlist=[(search[0]-1,search[1]-1),(search[0]-1,search[1]),(search[0]-1,search[1]+1),(search[0],search[1]-1),(search[0],search[1]+1),(search[0]+1,search[1]-1),(search[0]+1,search[1]),(search[0]+1,search[1])]

    for sl in searchlist:

        if check(sl[0],sl[1])==1 and 1<=sl[0]<=n and 1<=sl[1]<=n and USEDLIST[sl[0]][sl[1]]==0:
            d.append((sl[0],sl[1]))
            USEDLIST[sl[0]][sl[1]]=1

    if USEDLIST[C[0]][C[1]]==1:
        print("YES")
        break

else:
    print("NO")

#for i in USEDLIST:
#    print(i)
        
