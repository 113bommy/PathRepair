ls=[]
for i in range(3):
    s =input()
    ls.append(s.split())

for i in range(3):
    for j in range(3):
        ls[i][j]=int(ls[i][j])

for i in range(1,10**5):
    ls[0][0]=i
    ls[1][1]=sum(ls[0])-ls[1][0]-ls[1][2]
    ls[2][2] =sum(ls[0])-ls[2][0] -ls[2][1]
    if sum(ls[0])==sum(ls[1])==sum(ls[2])==ls[0][0]+ls[1][1]+ls[2][2]==ls[0][2]+ls[1][1]+ls[2][0]:
        break
for i in range(3):
    print(*ls[i])

