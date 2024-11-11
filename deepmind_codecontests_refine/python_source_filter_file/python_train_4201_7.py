import sys
if __name__ == '__main__':
  fstring=sys.stdin.readline().rstrip()
  counter=0
  mayu=minu=ini=0
  minimo=100000
  l=len(fstring)
  mayusculasizq=[]
  minusculasizq=[]
  primerosmayus=[0]
  for i in range(l):
    if ord(fstring[i])>=97:
      ini=ini+1
    if ord(fstring[l-1-i])<=90:
      minu=minu+1
    else:
      mayu=mayu+1
    primerosmayus.append(ini)
    minusculasizq.append(minu)
    mayusculasizq.append(mayu)
  minusculasizq.append(minusculasizq[l-1])
  mayusculasizq.append(mayusculasizq[l-1])
  primerosmayus=list(reversed(primerosmayus))
  for i in range(l+1):
    minimo=min(minimo,primerosmayus[i]+minusculasizq[i],primerosmayus[i]+mayusculasizq[i])
  print(minimo)
    