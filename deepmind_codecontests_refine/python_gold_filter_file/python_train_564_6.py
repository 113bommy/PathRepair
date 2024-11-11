a=input()
b=input()
j=0
c=0
flag=True
for i in range(len(a)):
    if a[i]==b[j]:
        j+=1
    if j>=len(b):
        break
if j==len(b):
    print("automaton")
elif sorted(a)==sorted(b):
    print("array")
else:
  for i in b:
    if a.count(i)<b.count(i):
      flag=False
      break
  if flag==True:
    print("both")
  else:
    print("need tree")