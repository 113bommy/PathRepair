a,b,c=1,0,0
exec('a,b,c=b,c,a+c;'*(int(input())-2))
print(c%(10**9+7))