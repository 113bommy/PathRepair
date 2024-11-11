m , n = map(int,input().split())
line1 = [int(nhap1) for nhap1 in input().split()]
line2 = [int(nhap2) for nhap2 in input().split()]
Limak , Rade  = 0 ,0
add , radd = 0,0
for i in range(m):
    add = add + line2[i]
    radd = radd + line2[m-1-i]
    a = line1[i] -n*add
    b = line1[m-1-i]- n*radd
    if (a <0):
        a=0
    if (b <0):
        b=0
    Limak = Limak + a
    Rade = Rade +b
if(Limak > Rade):
    print('Limax')
elif (Limak < Rade):
    print('Radewoosh')
else:
    print('Tie')
