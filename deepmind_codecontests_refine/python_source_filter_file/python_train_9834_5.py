n=int(input())
print("+------------------------+")
print("|",end="")
a=0
b=0
c=0
if n>=4:
   for i in range(n-4):
      if i%3==0:a+=1
      elif i%3==1:b+=1
      else:c+=1

if n>=1:print("O.",end="")
else:print("#.",end="")
for i in range(1,11):
   if i>b:print("#.",end="")
   else:print("O.",end="")
print("|D|)")

print("|",end="")
if n>=2:print("O.",end="")
else:print("#.",end="")
for i in range(1,11):
   if i>a:print("#.",end="")
   else:print("O.",end="")
print("|.|")

print("|",end="")
if n>=3:print("O.",end="")
else:print("#.",end="")
print("......................|")

print("|",end="")
if n>=4:print("O.",end="")
else:print("#.",end="")
for i in range(1,11):
   if i>c:print("#.",end="")
   else:print("O.",end="")
print("|.|)")

print("+------------------------+")