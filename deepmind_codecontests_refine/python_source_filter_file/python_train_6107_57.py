L=[int(i) for i in input()]
a=L[0]
d=0

    
for i in range( len(L)) :
    if L[i]==a:
        d=d+1
while d==len(L):
    
    d=0
    L=[]
    L=[int(i) for i in input()]
    a=L[0]
    for i in range( len(L)) :
        if L[i]==a:
            d=d+1
if d!=len(L):
    a=L[0]
    c=0
    for i in range( len(L)) :
        if L[i]==a:
            c=c+1
            if c==7 :
                break
        else:
            a=L[i]
            c=1
    if c > 6 :
        print("Yes")
    else:
        print("No")
