
n, k, l, c, d, p, nl, np = map(int,input().split())
drink = k*l//nl
slices = c*d
salt = p//np
print(min(drink,slices,salt)//n)