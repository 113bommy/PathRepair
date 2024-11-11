x=input()
y=input()
a = y.split()
b=[]
for num in a:
    b.append(int(num))
b.sort()    
i=0
q=0
k = len(a)
for i in range(0, len(a)-1 ):
    d = int(b[i+1]) - int(b[i])
    if d != 1:
        
        q = q + d
    else:
        pass
        
print(q)        