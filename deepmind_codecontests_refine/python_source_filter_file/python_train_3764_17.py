a,b,c,d=map(int,input().split())
e=[a,b,c,d]
e.sort(reverse = True)
tam=0
f=[]
for i in range(0,len(e)-1):
      tam = e[i] - e[3]
      f.append(tam)
for i in range(0,len(f)):
      print(f[i],end=' ')
            