x=int(input())
#ij=[[0]*x for r in range(x)]
ij=[]
for i in range(x):
  row=list(map(int, input().split()))
  ij.append(row)
#print(ij)
summ=0
y=(x+1)//2-1
k=ij[y][y]
for i in range(x):
  summ+=ij[i][i]
  summ+=ij[i][x-i-1]
  summ+=ij[y][i]
  summ+=ij[i][y]
  print(summ)
summ-=3*k
print(summ)