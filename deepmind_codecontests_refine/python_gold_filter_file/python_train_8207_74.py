x=int(input())-1
ans=0
ans+=x//11*2
if x%11<6:
  ans+=1
elif x%11>5:
  ans+=2
print(ans)
