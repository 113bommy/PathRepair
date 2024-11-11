n=int(input())
nn=n//6
nr=n%6
if n==3:
  print(2,5,63)
elif n==4:
  print(2,5,20,63)
elif n==5:
  print(2,5,20,30,63)
else:
  Ans=[]
  count=0
  k=1
  while count<n:
    if k%6==2 or k%6==3 or k%6==4 or k%6==0:
      Ans.append(k)
      count+=1
    k+=1
  s=sum(Ans)
  if s%6==2:
    Ans.remove(8)
    Ans.append(6*(k//6))
  elif s%6==3:
    Ans.remove(9)
    Ans.append(6*(k//6))
  elif s%6==5:
    Ans.remove(9)
    Ans.append(6*(k//6)+4)
  print(*Ans)