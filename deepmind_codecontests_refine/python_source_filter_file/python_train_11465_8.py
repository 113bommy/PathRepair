t=int(input())
for i in range(t):
    d=float(input())
    if(d**2-4*d<0):print("N")
    else:
        print((d+(d**2-4*d)**0.5)/2,(d-(d**2-4*d)**0.5)/2)