n=int(input())
List=list(map(int, input().split()))
for x in range(1, len(List)):
    List[x]+=List[x-1]
for i in List:
    if i>=n:
        print(List.index(i)+1)
        exit()

n%=List[-1]
if n==0:
    n+=1
for i in List:
    if i>=n:
        print(List.index(i)+1)
        exit()