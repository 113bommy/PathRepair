a,b,c = 0,0,0
last = ""
for i in input():
    if i=='1':
        a+=1
    elif i=='0':
        b+=1
    else:
        c+=1
    last=i
if b+c>a:
    print("00")
if last!="0":
    a1, b1, c1 = a,b,c
    if last=="?":
        c1-=1
        a1+=1
    x=(-a1+b1+c1+(a1+b1+c1)%2)//2
    if 0<=x<=c:
        print("01")
if last!="1":
    a1, b1, c1 = a, b, c
    if last=="?":
        c1-=1
        b1+=1
    x=(-a1+b1+c1+(a1+b1+c1)%2)//2
    if 0<=x<=c:
        print("10")
if a+c>b+1:
    print("11")
