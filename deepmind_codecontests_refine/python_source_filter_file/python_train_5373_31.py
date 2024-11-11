s=input()
k=int(input()) #nb de lettres différentes à avoir
myList=sorted(s)
newList=[]
for i in myList:
  if i not in newList:
    newList.append(i)
n=len(newList) #nb de lettres différentes
m=len(myList) #nb de lettre au total
if k>m:
    print("impossible")
else:
    if n>=k:
        print("0")
    else:
        print(m-n)
