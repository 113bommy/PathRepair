l=[1,1]
t=0
for i in range(1,int(input())+1):
     l=l+[l[t]+l[t-1]]
     t+=1
     if i in l:
          print('O',end='')
     else:
          print('o',end='')