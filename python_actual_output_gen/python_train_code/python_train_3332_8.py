q = [str(i*i) for i in range(1, 44721)]
q.reverse()
n = input()
ans = ''
for i in q:
  cont = 0
  pos = 0
  for j in i:
    x = pos
    for k in n[x::]:
      pos+=1
      if(k == j):
        cont+=1
        break
  if(cont == len(i)):
    ans = str(len(n) - cont)
    break
if(ans == ''):
  print('-1')
else:
  print(ans)
