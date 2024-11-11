a,b,c=map(int,input().split())
z=(-b-(((b**2)-(4*a*c))**0.5))//(2*a)
z1=(-b+(((b**2)-(4*a*c))**0.5))//(2*a)
print(max(z,z1),min(z,z1),sep="\n")