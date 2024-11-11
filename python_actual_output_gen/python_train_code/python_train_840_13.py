while 1:
    try:a,b,c,d,e,f=map(int,input().split())
    except:break
    x=(c*d-a*f)/(b*d-a*e)
    print("%f %f"%((c-b*x)/a,x))