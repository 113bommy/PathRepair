a,b,c,d,e,f=[int(input()) for i in range(6)]
x,y=min(a,d),min(b,c,d)
print(max(e*x+f*min(b,c,d-x),f*y+e*min(a,d-x)))