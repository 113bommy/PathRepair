n=int(input())
k=int((-1+(8*n+1)**0.5)/2)
som=k*(k+1)//2
if n-som==0:
    print(k)
else:
    print
    (n-som)