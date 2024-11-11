class Num:
    cur, digits, di = 0, 0, {}

def dig(n):
    if "1"+"0"*(len(str(n))-1)==str(n):
        Num.cur += 1
        Num.digits += Num.cur
    else:
        Num.digits += Num.cur
    return Num.digits

def work(n):
    j=n
    start = 1
    Num.cur, Num.digits=0,0
    done = False
    while not done:
        next = dig(start)
        if n > next:
            n -= next
            start += 1
        else:
            done=True

    p=1
    while n >= 9*p*(10**(p-1)):
        n -= 9*p*(10**(p-1))
        p += 1
    starts = 10**(p-1)
    if n <= p:
        Num.di[j] = str(starts)[n-1]
    else:
        cv = int(n/p)
        starts += cv
        n -= cv*p
        if n==0:
            Num.di[j] = str(starts-1)[-1]
        else:
            Num.di[j] = str(starts)[n-1]

q = int(input())
li = []
for i in range(q):
    li.append(int(input()))

for j in sorted(li):
    work(j)
for j in li:
    print(Num.di[j])