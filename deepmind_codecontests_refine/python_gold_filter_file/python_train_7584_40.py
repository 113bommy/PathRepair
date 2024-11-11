ma=input()
mb=input()
mc=input()
mdic={"a":ma,"b":mb,"c":mc}
m="a"
ndic={"a":0,"b":-1,"c":-1}
while ndic[m]<len(mdic[m]):
  m=mdic[m][ndic[m]]
  ndic[m]+=1
print(m.upper())