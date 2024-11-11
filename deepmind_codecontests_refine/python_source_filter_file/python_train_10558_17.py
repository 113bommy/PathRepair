from sys import stdin



def solve(vec,v):
  v=list(v)
  lista=vec.split('|')
  l1,l2=list(lista[0]),list(lista[1])
  cont=0
  while cont<len(v):
    if len(l1)<len(l2):
        l1.append(v[cont])
        cont+=1
    else:
        l2.append(v[cont])
        cont+=1
  if len(l1)==len(l2):
    a1=''
    a2=''
    for i in range(len(l1)):
        a1=a1+str(l1[i])
        a2=a2+str(l2[i])
    print(a1+'|'+a2)
  else:
    print("Imposible")
    
def main():
  vec=stdin.readline().strip()
  v=stdin.readline().strip()
  solve(vec,v)
main()
