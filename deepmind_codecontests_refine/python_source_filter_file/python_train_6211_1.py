n = int (input ())
l=[]
d={}
for i in range (n) :
    ch = input()
    c= int (eval(ch))
    l.append(c)
    if (c in d ) :
        d[c]+=1
    else :
        d[c]=1
for i in range ( n) :
    print (d[l[i]] ,end=" ")
