from collections import defaultdict
def isSubsequence(S,T,List,pos,Pos):
    lenS = len(S)
    lenT = len(T)
    Sx = 0
    Tx = 0
    while(Tx<lenT and Sx<lenS):
        if(Pos[Sx]<=pos):
            Sx+=1
        elif(S[Sx] == T[Tx]):
            Sx+=1
            Tx+=1
        else:
            Sx+=1
    if(Tx == lenT):
        return True
    return False
S = input()
T = input()
List = [int(x) for x in input().split()]
N = len(List)
Pos = defaultdict(int)
for i in range(N):
    Pos[List[i]-1] = i
N = len(List)
l = 0
r = N-1
while(l<r):
    mid = (l+r)>>1
    if(isSubsequence(S,T,List,mid,Pos)):
        l = mid+1
    else:
        r = mid
print(l)
