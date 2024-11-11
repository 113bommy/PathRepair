a,b,c,d=map(int,input().split()) 
x = max(a*c,0,b*d,a*d,b*c)
print(x)