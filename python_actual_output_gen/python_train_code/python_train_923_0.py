N=int(input())
Hor=Ver=1

H=[]
V=[]
for I in range(N):
    Tmp=list(map(int,input().split()))
    H+=[Tmp[0]]
    V+=[Tmp[0]]
H.sort()
V.sort()
Tmp1=H[0]
Tmp2=V[0]
for I in range(1,N):
    Hor+=1 if not Tmp1==H[I] else 0
    Ver+=1 if not Tmp2==V[I] else 0
    Tmp1=H[I]
    Tmp2=V[I]
    
print(min(Hor,Ver))
