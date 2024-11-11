string=input()
c1=0
c2=0
for i in string:
      if(i.islower()):
            c1+=1
      elif(i.isupper()):
            c2+=1
if c1>c2:
    print(string.lower())
else:
    print(string.upper())