n,m=map(int,input().split())
student=[]
man=[]
for i in range(n):
  x,y=map(int,input().split())
  student.append([x,y])
for i in range(m):
  x,y=map(int,input().split())
  man.append([x,y])
for i in student:
  ans=[]
  for j in man:
    ans.append(abs(i[0]-j[0])+abs(i[1]-j[1]))
  print(ans.index(max(ans)))