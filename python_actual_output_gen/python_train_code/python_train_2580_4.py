a,b,c=1,0,0
exec('a,b,c=b,c,a+c;'*int(input()))
print(a%(1e9+7))