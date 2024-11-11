n=int(input())
s=input()
dicti={}
for i in range(n-2):
  if s[i:i+2] in dicti:
    dicti[s[i:i+2]]+=1
  else:
     dicti[s[i:i+2]]=1
maxi=0
d=''
for i in dicti:
  if dicti[i]>maxi:
    maxi=dicti[i]
    d=i
print(d)