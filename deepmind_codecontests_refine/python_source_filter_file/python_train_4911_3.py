n = int(input())
l=[]
number = ''
x=''
for i in range(n+1):
    number = number + str(i)
    if i>0:
        temp = number[::-1]
        x = number+ (temp[1:])
        x = x.replace("", " ")
        l.append(x[1:])
    else:
        l.append(number)
s = n*2
for i in l:
    print(s*" "+i+s*" ")
    s = s-2
l.pop()
l= l[::-1]
s=2
for i in l:
    print(s*" "+i)
    s = s+2