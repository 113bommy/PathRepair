n=int(input())
st=str(input())
p=[]
cont=0
def isok(ls):
  for i in range(len(ls)-1):
    if(ls[i]==ls[i+1]):
      #print(ls)
      ls.pop(i+1)
      #print(ls)
      return False
  return True
for i in st:
  p.append(i)
while(not isok(p)):
  cont+=1
print(cont)