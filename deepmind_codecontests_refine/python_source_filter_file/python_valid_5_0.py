t=int(input())
for ttt in range(t):
  n=int(input())
  a1=input()
  a2=input()
  aa1=[]
  aa2=[]
  for pro in range(n):
    aa1.append(a1[pro])
    aa2.append(a2[pro])
  ones=[]
  ans=0
  for k in range(n):
    if(a1[k]=='1'):
      ones.append(k)
    if(a1[k]=='0' and a2[k]=='1'):
      ans+=1
  i=0
  if(len(ones)>1):
   while(i<len(ones)-1):
    if(ones[i+1]==ones[i]+1):
      if(aa2[ones[i]]=='1' and aa2[ones[i+1]]=='1'):
        ans+=2
        i+=2
      elif(aa2[ones[i]]=='1' and aa2[ones[i+1]]=='0'):
        ans+=1
        i+=2
      elif(aa2[ones[i]]=='0' and aa2[ones[i+1]]=='1'):
        ans+=1
        aa2[ones[i+1]]='0'
        i+=1
      else:
        i+=2
    else:
      i+=1
  print(ans)
      