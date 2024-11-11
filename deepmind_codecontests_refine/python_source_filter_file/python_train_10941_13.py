import sys
n=int(input())
a=sys.maxsize
b=sys.maxsize
c=sys.maxsize
ab=sys.maxsize
bc=sys.maxsize
ac=sys.maxsize
abc=sys.maxsize
ma=sys.maxsize

for i in range(n):
    x,y=input().split()
    x=int(x)
    if(y=='A'):
        a=min(a,x)
    elif(y=='B'):
        b=min(b,x)
    elif(y=='C'):
        c=min(c,x)
    elif(y=='AB' or y=='BA'):
        ab=min(ab,x)
    elif(y=='BC' or y=='CB'):
        bc=min(bc,x)
    elif(y=='AC' or y=='CA'):
        ac=min(ac,x)
    else:
        abc=min(abc,x)

ma=min(ma,a+b+c)        
        
ma=min(ma,a+bc)
ma=min(ma,b+ac)
ma=min(ma,c+ac)
ma=min(ma,ab+bc)
ma=min(ma,bc+ac)
ma=min(ma,ac+ab)
ma=min(ma,abc)
if(ma==sys.maxsize):
    print(-1)
else:
    print(ma)

        
    
