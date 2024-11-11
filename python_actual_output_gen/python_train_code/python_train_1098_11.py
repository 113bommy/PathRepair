n=int(input())
a=[]
for i in range(n) :
    x=input()
    a.append(x)
b=list(set(a))
c=[]
for i in range(len(b)) :
    c.append(b.count(b[i]))
print(b[c.index((max(c)))])
