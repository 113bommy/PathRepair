a,b,c=input().strip().split()
a,b,c=int(a),int(b),int(c)
m=int(input())
usb=[]
ps=[]
cnt=0
sum=0
up=[]

for a0 in range(m):
    l=input().strip().split()
    if l[1]=="USB":
        usb.append(l[0])
    else:
        ps.append(l[0])

usb=[int(i) for i in usb]
ps=[int(j) for j in ps]

usb.sort()
ps.sort()

lu=len(usb)
lp=len(ps)

if lu>=a:
    cnt+=a
    for i in usb[0:a]:
        sum+=i
    for j in usb[a:lu]:
        up.append(j)
else:
    cnt+=lu
    for i in usb:
        sum+=i
        
if lp>=b:
    cnt+=b
    for i in ps[0:b]:
        sum+=i
    for j in ps[b:lp]:
        up.append(j)
else:
    cnt+=lp
    for i in ps:
        sum+=i
        
up.sort()
lup=len(up)
if lup>=c:
    cnt+=c
    for i in up[0:b]:
        sum+=i
else:
    cnt+=lup
    for i in up:
        sum+=i

print (cnt,sum)