#Bulbbasaur
n=input()
a=['B','u','l','b','a','s','r']
b=7*[0]
c=[1,2,1,2,2,1,1]
d=7*[0]
for i in range(7):
    b[i]=n.count(a[i])
for i in range(7):
    d[i]=b[i]//c[i]
print(min(d))
    
