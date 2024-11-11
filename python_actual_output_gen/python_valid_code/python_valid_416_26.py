s,t,a,b,x,y=map(int,open(0).read().split())
i=(x-a)*s
j=(b-y)*t-i
print(i//j*2+(i%j!=0)if j else'infinity')