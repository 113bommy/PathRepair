q=int(input())
l=[] 
for i in range(0,q):
  nq=int(input())
  students=[int(i) for i in input().split()]
  l.append(students)
for i in range(0,q):
  team1=[l[i][0]]
  team2=[]
  v=True
  for s in l[i]:
    for steam1 in team1:
        d=steam1-s
        if (abs(d)==1):
            v=False
            break
    if v==False :
        break
  if (not v):
      print("2")
  if (v):
      print("1")
