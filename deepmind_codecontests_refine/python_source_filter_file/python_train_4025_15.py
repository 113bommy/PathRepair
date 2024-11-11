hh,mm=map(int,input().split())
h,d,c,n=map(int,input().split())
if hh>=20:
    print((h+n-1)//n*c)
    quit()
mm1=1200-hh*60-mm
print(min((h+n-1)//n*c,(h+mm1*d+n-1)//n*(c*0.8)))
