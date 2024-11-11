input()
a=[]
b=[]
c=[]
x = list( map(int, input().split()) )
for i in range(1,len(x)):
    if x[i] == 1:
        a.append(i)
    if x[i] == 2:
        b.append(i) 
    if x[i] == 3:
        c.append(i)        
n= min(len(a),len(b),len(c))
print(n)
for i in range(n):
    print(a[i],b[i],c[i])      