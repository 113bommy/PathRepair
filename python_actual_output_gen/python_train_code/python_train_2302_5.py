s=input()
res=0
flag=s[0]=="1"
for c in s[1:]:
 res+=int(c)
 if c!="0":
  flag=False
if flag:
 print(10)
else:
 print(res)