a,b,c,d=input().strip().split(' ')
a,b,c,d=(int(a),int(b),int(c),int(d))
x=a/b
y=c/d
print(x/(1-x*y))