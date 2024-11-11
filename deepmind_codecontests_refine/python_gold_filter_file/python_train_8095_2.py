pnt=[]
n=int(input())
for i in range(n):
  pnt.append(list(map(int,input().split())))

z=[]
w=[]

for i in pnt:
  z.append(i[0]+i[1])
  w.append(i[0]-i[1])
print(max(max(z)-min(z),max(w)-min(w)))
