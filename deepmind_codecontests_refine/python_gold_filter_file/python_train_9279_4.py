ch=input()
l=ch.split( )
y=int(l[2])
n=int(l[0])
x=int(l[1])
diff=y-n+1
if diff <=0 :
    print(-1)
else:
    
 l=[]
 l.append(diff)
 for i in range(n-1):
    l.append(1)
 def check(t):
    sd=0
    ss=0
    for e in t:
        ss+=e
        sd+=e**2
    if sd>=x:
        if ss<=y:
            return True
    else :
        return False

 test=check(l)
 if test :
    for s in range(n):
        print(l[s])
 else :
    print(-1)
