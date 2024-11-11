def solve(word):
  abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  cba=[i for i in range(len(abc))]
  hashed=dict(zip(abc,cba))
  hashed_2=dict(zip(cba,abc))
  word=list(word)
  if len(word)<3:
    print("YES")
    return
  w="".join(word)
  salida=[hashed[word[0]],hashed[word[1]]]
  while len(salida)<len(word):
    a=salida[-2]+salida[-1]
    salida.append(a%26)
  
  resp=""

  for i in salida:
    resp=resp+hashed_2[i]
  

  if resp==w:
    print("YES")
  else:
    print("NO")



W=input().strip()
solve(W)
