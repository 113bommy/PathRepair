v,m =[int(i) for i in input().split()]
if v==1 and m==10:
    print('- 1')
else:
    if int(m)==10:
        if int(v)%2==1:
            v=v//2
            print('10' *v + '0')
        else:
            v=v//2
            print('10'*v)
    else:
        print(str(m) * v)