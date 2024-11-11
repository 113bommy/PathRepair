r=input().split()
length=int(r[0])
digit=int(r[1])
digitc=int(r[1])
le=0
m=[]
ans1=0
ans2=0
if length==1 and digit <= 9*length:
    print(digit,digit)
elif digit==0 or digit > 9*length:
    print("-1 -1")   
else:
    while le != length:
        if digitc>=9:
            m.append(9)
            digitc -= 9
            le += 1
        else:
            m.append(digitc)
            le += 1
            digitc = 0
    for i in range(length):
        ans1+=m[i]*10**(length-i-1)

    if digit>9 and length+8 < digit:
        for i in range(length):
            if m[i] != 0:
                ans2 += m[i]*10**(i)
            else:
                mid = int(ans2/(10**(i-1)))
                midd = ans2%(10**(i-1))
                ans2 = int(10**i*mid+midd)
    elif digit<=9:
        ans2=10**(length-1)+digit-1
    elif digit>9 and length+8 >= digit:
        u=digit-1
        k=0
        l=[]
        while k != length:
            if u>=9:
                l.append(9)
                u -= 9
                le += 1
            else:
                l.append(u)
                k += 1
                u = 0
        for i in range(length):
            ans2 += l[i]*10**(i)
        ans2 += 10**(length-1)
    print(ans2,ans1)
