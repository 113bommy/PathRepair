ch=input()
vowel="AEIOU"
c=0
p=0
for i in ch :
      if i in vowel:
            c=0
      else:
            c+=1
      p=max(p,c)
print(p+1)