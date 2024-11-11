s=input()
l=s.split(":",2)
h=int(l[0])
m=int(l[1])
if h>=0 and h<1 :
    if m>0 :
        print(60-m+10)
    else :
        print(0-m)
if h>=1 and h<2 :
    if m>10 :
        print(60-m+20)
    else :
        print(10-m)
if h>=2 and h<3 :
    if m>20 :
        print(60-m+30)
    else :
        print(20-m)
if h>=3 and h<4 :
    if m>30 :
        print(60-m+40)
    else :
        print(30-m)
if h>=4 and h<5 :
    if m>40 :
        print(60-m+50)
    else :
        print(40-m)
if h>=5 and h<6 :
    if m>50 :
        print(300-m+1)
    else :
        print(50-m)
if h>=6 and h<7 :
        print(240-m+1)
if h>=7 and h<8 :
        print(180-m+1)
if h>=8 and h<9 :
        print(120-m+1)
if h>=9 and h<10 :
        print(60-m+1)
if h>=10 and h<11 :
    if m>1 :
        print(60-m+2)
    else :
        print(1-m)
if h>=11 and h<12 :
    if m>11 :
        print(60-m+21)
    else :
        print(11-m)
if h>=12 and h<13 :
    if m>21 :
        print(60-m+31)
    else :
        print(21-m)
if h>=13 and h<14 :
    if m>31 :
        print(60-m+41)
    else :
        print(31-m)
if h>=14 and h<15 :
    if m>41 :
        print(60-m+51)
    else :
        print(41-m)
if h>=15 and h<16 :
    if m>51 :
        print(300-m+2)
    else :
        print(51-m)
if h>=16 and h<17 :
        print(240-m+2)
if h>=17 and h<18 :
        print(180-m+2)
if h>=18 and h<19 :
        print(120-m+2)
if h>=19 and h<20 :
        print(60-m+2)
if h>=20 and h<21 :
    if m>2 :
        print(60-m+12)
    else :
        print(2-m)
if h>=21 and h<22 :
    if m>12 :
        print(60-m+22)
    else :
        print(12-m)
if h>=22 and h<23 :
    if m>22 :
        print(60-m+32)
    else :
        print(32-m)
if h>=23 and h<24 :
    if m>32 :
        print(60-m)
    else :
        print(32-m)