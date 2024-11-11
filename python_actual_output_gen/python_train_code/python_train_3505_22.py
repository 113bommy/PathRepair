a,b,c,x=[int(input()) for _ in range(4)]
print(len([1 for i in range(a+1) for j in range(b+1) if (x-500*a-100*b)%50==0 and 0<=(x-500*a-100*b)//50 <=c]))
