a=input()
b=int(a[:-1])
c=a[-1]
time=((b-1)//4)*16+((b-1)%2)*6
if c=='f':
    time=time+1
if c=='e':
    time=time+2
if c=='d':
    time=time+3
if c=='a':
    time=time+4
if c=='b':
    time=time+5
if c=='c':
    time=time+6
print(time)



