n=input()
List=list(map(int,input().split()))
ans=0
while all(l%2==0 for l in List):
  List[l/2 for l in List]
  ans+=1
print(ans)