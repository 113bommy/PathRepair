p,q,r=input("").split(" ")
p=int(p)
q=int(q)
r=int(r)
a,b,c=input("").split(" ")
a=int(a)
b=int(b)
c=int(c)
count=0
if p<=a:
                count+=1
                a-=p
if q<=a+b:
                count+=1
                d=q-(a+b)
if r<=d+c:
                count+=1
if count==3:
                print("YES")
else:
                print("NO")
                
