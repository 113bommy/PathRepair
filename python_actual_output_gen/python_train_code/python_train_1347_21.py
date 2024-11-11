def wb(x):
 ans=0
 for c in x:
  if c=="7":
   ans=ans+1
  ans=ans*2
 return ans
i=input()
pos=2**len(i)-1
pos+=wb(i)
print(pos)