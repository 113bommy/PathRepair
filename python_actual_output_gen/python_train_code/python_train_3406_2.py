while True:
    try:
        xa,ya,xb,yb,xc,yc,xd,yd=map(float,input().split())
    except EOFError:
        break
    if (ya-yb)*(yc-yd)+(xa-xb)*(xc-xd)<=1e-10:
        print("YES")
    else:
        print("NO")
