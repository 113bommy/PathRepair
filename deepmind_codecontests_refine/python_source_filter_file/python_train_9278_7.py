import math
n=int(input())
nsquare=int(math.sqrt(n))
if(n==nsquare*nsquare):
  print(2*nsquare)
elif(n-nsquare*nsquare<nsquare):
  print(2*nsquare+1)
else:
  print(2*nsquare+2)
