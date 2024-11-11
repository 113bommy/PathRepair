y = input()
x = {i: y.count(i) for i in set(y)}
print('YNEOS'[(any(x[i]<2 for i in x)if len(x)==2 else len(y)<4)if 1<len(x)<4 else 1::2])