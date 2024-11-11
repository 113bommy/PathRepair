n=int(input("n="))
k=int((-1+(8*n+1)**0.5)/2)
s=k*(k+1)//2
if(n-s==0):
    print(k)   
else:
    print(n-s)