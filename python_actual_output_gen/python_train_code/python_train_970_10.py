x=int(input())
h,m=map(int,input().split())

def islucky(h,m):
    h1=h%10
    h2=(h-h1)/10
    m1 = m % 10
    m2 = (m - m1) / 10
    if h1==7 or h2==7 or m1==7 or m2==7:
        return True
    else:
        return False

count=0
th=h
tm=m
if islucky(h,m):
    print("0")
else:
    while not islucky(th, tm):
        if tm - x >= 0:
            tm -= x
            count += 1
        else:
            if th-1<0:
                th=23
            else:
                th-=1
                tm = 60 + tm - x
                count += 1
    print(count)






