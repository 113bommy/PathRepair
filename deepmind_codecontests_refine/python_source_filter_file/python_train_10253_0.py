V1,V2=map(int,input().split())
T,D=map(int,input().split())
Arr=[0]*101
Arr2=[0]*101
for I in range(1,T+1):
    Arr[I]=V1
    V1+=D
    Arr2[T+1-I]=V2
    V2+=D
Ans=K=0
for I in range(1,T):
    if Arr2[I+1]-Arr[I]>D:
        K=I
        Ans+=Arr[I]
Ans+=Arr[K+1]
K+=1
for J in range(K,T+1):
    Ans+=Arr2[J]
print(Ans)
