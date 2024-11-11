#087_B
a,b,c,x=[int(input()) for i in range(4)]
print(sum([500*p+100*q+10*r==x for p in range(a+1) for q in range(b+1) for r in range(c+1)]))