pole=input().split()
n=int(pole[0])
d=int(pole[1])
pervayakoord=[0,d]
vtorayakoord=[d,0]
tretiyakoord=[n,n-d]
chetvkoord=[n-d,n]
kolvo_kuzn_in_pole=0
kuzn_vsego=int(input())
for i in range(kuzn_vsego):
    vvod=input().split()
    x=int(vvod[0])
    y=int(vvod[1])
    if y<=(x+d) and y<=(-x+(2*n-x)) and y>=(x-d) and y>=(-x+d):
        print('YES')
    else:
        print('NO')
