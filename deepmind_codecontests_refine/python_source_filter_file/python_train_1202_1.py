s=input()
if len(s)%2!=0:
    print(-1)
else:
    u=s.count("U")
    d=s.count("D")
    r=s.count("R")
    l=s.count("L")
    print(min(abs(u-d),abs(r-l)))