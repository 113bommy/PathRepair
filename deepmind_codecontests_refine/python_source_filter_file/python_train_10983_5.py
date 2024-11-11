a=input()
cnt=0
c=0
for i in range(0,len(a)):
    if ord(a[i])>=97 & ord(a[i])<=123:
        cnt=cnt+1
    else:
        c=c+1
if cnt>=c:
    print(a.lower())
else:
    print(a.upper())