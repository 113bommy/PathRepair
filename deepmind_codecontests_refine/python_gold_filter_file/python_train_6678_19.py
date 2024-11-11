from collections import Counter
N = int(input())
List = [int(x) for x in input().split()]
Dict = Counter(List)
Val,Count = Dict.most_common(1)[0]
print(N-Count)
Index = List.index(Val)
for i in range(Index,N):
    if(List[i]>Val):
        print(2,i+1,i)
    elif(List[i]<Val):
        print(1,i+1,i)
for i in range(Index,-1,-1):
    if(List[i]>Val):
        print(2,i+1,i+2)
    elif(List[i]<Val):
        print(1,i+1,i+2)




