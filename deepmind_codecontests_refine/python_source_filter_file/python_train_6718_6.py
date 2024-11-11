x=input()
d=x.split(" ", 3)
F=int(d[0])
I=int(d[1])
T=int(d[2])
fr=[]
it=[0] * 10
ret=0
for i in range(0, F):
  fr.append(input())
  for j in range(0, I):
    if(fr[i][j]=='Y'):
      it[j]=it[j]+1
      if(it[j]==T):
        ret=ret+1
print(ret)
#kitten