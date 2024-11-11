n,*a=map(int,open(0).read().split())
q,m=divmod(sum(a),n*-~n//2)
print('YNEOS'[any((y-x-q+m)%n or y-x>q for x,y in zip(a,a[1:]))::2])