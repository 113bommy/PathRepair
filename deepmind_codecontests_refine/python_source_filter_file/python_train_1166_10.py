a = int(input())
b = int(input())
c = int(input())
d = int(input())
f1 = int(input())
f2 = int(input())
a1,a2 = 0, 0
if(f2 > f1):
    while(b>0 and c >0 and d >0):
        a1+=f2
        b-=1
        c-=1
        d-=1
    while(a >0 and d > 0):
        a2 += f1
        a-=1
        d-=1
else:
    while(a >0 and d > 0):
        a2 += f2
        a-=1
        d-=1
    while(b>0 and c >0 and d >0):
        a1+=f1
        b-=1
        c-=1
        d-=1
print(a1+a2)
