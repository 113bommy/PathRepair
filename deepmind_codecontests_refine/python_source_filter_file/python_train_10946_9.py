[a,b,c] = (input().split(' '))
a = int(a)
b = int(b)
c = int(c)
days = 0;

factor = 10000000
while factor!=1:
    while a>3*factor and b>2*factor and c>2*factor:
        a -= 3*factor
        b -= 2*factor
        c -= 2*factor
        days += 7*factor
    factor /= 10

while a>2 and b>1 and c>1:
    a -= 3
    b -= 2
    c -= 2
    days += 7

if c>1 and b>1:
    if a==0:
        days += 2
    elif a==1:
        days += 5
    elif a==2:
        days += 4

elif c>1 and a>2:
    if b==0:
        days += 3
    elif b==1:
        days += 6
    
elif b>1 and a>2:
    if c==0:
        days += 4
    elif c==1:
        days += 6

elif c>1:
    if b==0 and a==0:
        days += 1
    elif b==0 and a==1:
        days += 2
    elif b==0 and a==2:
        days += 2
    elif b==1 and a==0:
        days += 2
    elif b==1 and a==1:
        days += 4
    elif b==1 and a==2:
        days += 5

elif b>1:
    if c==0 and a==0:
        days += 1
    elif c==0 and a==1:
        days += 2
    elif c==0 and a==2:
        days += 4
    elif c==1 and a==0:
        days += 2
    elif c==1 and a==1:
        days += 3
    elif c==1 and a==2:
        days += 5

elif a>2:
    if b==0 and c==0:
        days += 2
    elif b==0 and c==1:
        days += 2
    elif b==1 and c==0:
        days += 3
    elif b==1 and c==1:
        days += 5

else:
    days += (a+b+c)
print(int(days))
