t=int(input())

for i in range(t):
  d={}
  n=int(input())
  min=200001
  l=[]
  l = list(map(int, input().split()))

  if n==1:
    print("-1")
    continue
 
  else:

    for j in range(n):

      if l[j] in d.keys():
        size=len(d[l[j]])
        if ((j-d[l[j]][size-1]+1)<min):
          min=j-d[l[j]][size-1]+1
        d[l[j]].append(j)
      else:
        d[l[j]]=[j]
    
    if min<2 :
      print("-1")
    else:
      print(min)
        



