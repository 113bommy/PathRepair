n=input()
n=n.split()
b=0
if int(n[0])==1 or int(n[0])==3 or int(n[0])==5 or int(n[0])==7 or int(n[0])==8 or int(n[0])==10 or int(n[0])==12:
    a=31
    a=a-(8-int(n[1]))
    if a%7==0:
        b=1+(a//7)
        print (b)
    else:
        b=1+((a//7)+1)
        print(b)
elif int(n[0])==4 or int(n[0])==6 or int(n[0])==9 or int(n[0])==11:
    a=30
    a=a-(8-int(n[1]))
    if a%7==0:
        b=1+(a//7)
        print (b)
    else:
        b=1+((a//7)+1)
        print(b)
else:
    a=29
    a=a-(8-int(n[1]))
    if a%7==0:
        b=1+(a//7)
        print (b)
    else:
        b=1+((a//7)+1)
        print(b)
