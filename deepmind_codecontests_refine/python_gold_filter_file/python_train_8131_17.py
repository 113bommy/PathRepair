n,k=map(int,input().split())
List=list(set(list(map(int,input().split()))))
List.sort()
print(List[0])
for i in range(0,k-1):
    if(i<len(List)-1):
        print(List[i+1]-List[i])
    else:
        print(0)


