m=int(input())
l=[list(map(int,input().split())) for i in range(m)]
ct=0;sum=0
for i in range(m):
  ct+=l[i][0]*l[i][1]
  sum+=l[i][1]
print(sum-1+((ct-1)//9))