h1,h2=map(int,input().split())
k1,k2=map(int,input().split())
a,b,c,d=map(int,input().split())
e,f,g,h=h1*a,h2*b,k1*a,k2*b
o,n,m,v=h1//10*c,h2//10*d,k1//10*c,k2//10*d
z,y=o+n+e+f,m+v+g+h
if z>y:
    print("hiroshi")
elif z<y:
    print("kenjiro")
elif z==y:
    print("even")
