input()
*p,=input().split()
print('NO' if 2<sum([1 for i,j in zip(p,sorted(p)) if i!=j]) else 'YES')