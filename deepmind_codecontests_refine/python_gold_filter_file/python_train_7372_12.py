import math
D,G=[int(s) for s in input().split()]
ls=[[int(s) for s in input().split()] for i in range(D)]
maxD=2**D-1
def need(num):
  val=num
  score=0
  prob=0
  for i in range(D):
    if val%2==1:
      score+=ls[i][0]*(i+1)*100+ls[i][1]
      prob+=ls[i][0]
    val//=2
  if score>=G:
    return prob
  else:
 #   print(score)
    k=int(math.log2(num^maxD))
    x=(score-G)//((k+1)*100)
    if -x<=ls[k][0]:
      return -x+prob
    else:
      return 10000
print(min([need(i) for i in range(2**D)]))    
      