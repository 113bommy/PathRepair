a=input()
b=input()
c=list()
for i,j in zip(a,b):
    if(i!=j):
        c.append('1')
    else:
        c.append('0')
c="".join(c)
c=str(c)