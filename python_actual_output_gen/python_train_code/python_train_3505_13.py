a,b,c,x=[int(input()) for _ in range(4)]
print([500*i+100*j+50*k for i in range(a) for j in range(b) for k in range(c)].count(x))