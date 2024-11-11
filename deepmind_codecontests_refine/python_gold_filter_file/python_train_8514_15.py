from bisect import bisect_left
a=input()
b=input()
c=[[]for i in range(26)]
for i in range(len(a)):
  c[ord(a[i])-97].append(i)

m=-1
ans=0
roop=0
for i in range(len(b)):
  s=ord(b[i])-97
  if c[s]==[]:
    print(-1)
    exit()
  else:
    p=bisect_left(c[s],m+1)
    if p<len(c[s]):
      m=c[s][p]
    else:
      roop+=1
      m=c[s][0]
print(roop*len(a)+m+1)
        
        