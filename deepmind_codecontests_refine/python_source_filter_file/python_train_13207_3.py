g=[[0]*5 for _ in[0]*5]
for i in range(9):
 e=input()
 for j in range(4+i%2):
  if int(e[j]):
   if i%2:g[i//2][j]+=4;g[i//2+1][j]+=1
   else:r=g[i//2];r[j]+=2;r[j+1]+=8
y,x=0,1
k=1
a=[1]
while 1:
 k+=2
 for _ in[0]*4:
  k+=1
  if g[y][x]&int(2**(k%4)):a+=[k%4];break
 if k%2:x+=1-2*((k%4)>0)
 else:y+=2*((k%4)>0)-1
 if x+y==0:break
print(''.join('URDL'[c]for c in a))
