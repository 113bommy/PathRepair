s=input()
t=input()
r=[]
a=ord(s[0])-96
c=ord(t[0])-96
b=int(s[1])
d=int(t[1])
e=0
if a<c:
    if b<d:
        while b!=d and a!=c:
            a=a+1
            b=b+1
            r.append("RU")
            e=e+1
        if b==d:
            while(a!=c):
                a=a+1
                e=e+1
                r.append("R")
        else:
            while(b!=d):
                b=b+1
                e=e+1
                r.append("U")
    elif b==d:
        while(a!=c):
            a=a+1
            e=e+1
            r.append("R")
    else:
        while b!=d and a!=c:
            a=a+1
            b=b-1
            r.append("RD")
            e=e+1
        if b==d:
            while(a!=c):
                a=a+1
                e=e+1
                r.append("R")
        else:
            while(b!=d):
                b=b-1
                e=e+1
                r.append("U")
else:
    if b<d:
        while b!=d and a!=c:
            a=a-1
            b=b+1
            r.append("LU")
            e=e+1
        if b==d:
            while(a!=c):
                a=a-1
                e=e+1
                r.append("L")
        else:
            while(b!=d):
                b=b+1
                e=e+1
                r.append("U")
    elif b==d:
        while(a!=c):
            a=a-1
            e=e+1
            r.append("L")
    else:
        while b!=d and a!=c:
            a=a-1
            b=b-1
            r.append("LD")
            e=e+1
        if b==d:
            while(a!=c):
                a=a-1
                e=e+1
                r.append("L")
        else:
            while(b!=d):
                b=b-1
                e=e+1
                r.append("D")        
print(e)
for i in r:
    print(i)

        
             
