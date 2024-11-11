t=int(input())
for i in range(t):
  n=int(input())
  l=[int (x) for x in input().split(" ")]
  d={}
  for i in l:
    b=str(bin(i))
    b=b[::-1]
    z=b.rfind("1")
    if z not in d:
      l2=[]
      l2.append(i)
      d[z]=l2
     # print(d)
    else:
      d[z].append(i) 
  count=0
  for i in d:
    if (len(d[i])>1):
      count+=((len(d[i]))*(len(d[i])-1)/2)
  print(count)
  