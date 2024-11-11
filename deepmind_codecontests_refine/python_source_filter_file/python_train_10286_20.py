input()
*p,=input().split()
print('YNEOS'[2<sum(i!=j for i,j in zip(p,sorted(p)))::2])