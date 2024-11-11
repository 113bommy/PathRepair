s,r=list(map(int,input().split()))
if s>r:
    temp=s/2
    dip=temp/(r+1)
    cert=r*dip
    print("{} {} {}".format(dip,cert,s-dip-cert))
else:
    print ("{} {} {}".format('0','0',s))