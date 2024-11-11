lis = [int(k) for k in input().split()]
n, k, l, c, d, p, nl, np= lis[0],lis[1],lis[2],lis[3],lis[4],lis[5],lis[6],lis[7]
drink = k*l
slices  = c*d
salt = p
lis1 = []
lis1.append(drink//(n*nl))
lis1.append(slices//n)
lis1.append(salt//(n*np))
lis1.sort()
print(lis1)
