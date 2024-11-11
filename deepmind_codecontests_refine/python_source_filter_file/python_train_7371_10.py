s=int(input())
List=[]
while s not in List:
  List.append(s)
  if s%2==0:
    s=s/2
  else:
    s=3*s+1
print(len(List))