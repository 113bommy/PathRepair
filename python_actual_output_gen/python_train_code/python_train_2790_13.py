n,k=map(int,input().split())
List=list(set(list(map(int,input().split()))))
List.sort()
print(List[0])
for i in range(len(List)):
    if(i<len(List)-1):
        print(List[i+1]-List[i])
    else:
        print(0)


