n=int(input())
s=input()
start=0
pedra=0
lista=s.split('-')
for k in range(len(lista)-1):
  if k==len(lista)-2 and lista[k]=='':
    break
  pedra+=len(lista[k])
  pedra-=1
  if pedra<0:
    start=-pedra
val=s.count('+')-s.count('-')
print(start+val)