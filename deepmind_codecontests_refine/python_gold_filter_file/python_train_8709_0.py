a={"purple":"Power","green":"Time","blue":"Space","orange":"Soul","red":"Reality","yellow":"Mind"}
n=int(input())
b=[]
for i in range(n):
    x=input()
    b.append(x)
c=["purple","green","blue","orange","red","yellow"]
print(6-len(b))
for i in c:
    if i not in b:
        print(a[i])