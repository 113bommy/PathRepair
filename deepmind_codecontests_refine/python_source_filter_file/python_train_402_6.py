for e in iter(input,'0'):
 a={tuple(map(int,input().split())) for _ in range(int(e))}
 s,t=a[0]
 b={tuple(map(int,input().split())) for _ in range(int(input()))}
 for x,y in b:
  flag = True
  for u,v in a[1:]:
   if(x+u-s,y+v-t)not in b:
    flag = False
    break
  if flag == True:
   print(x - s, y - t)
   break
