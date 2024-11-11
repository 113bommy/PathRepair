n, k = map(int,input().split())
if k==0:
    print ("0 0")
    exit(0)
mi = 1 if k<n else 0
ma=0
if k< n//3:
    ma = k*2
else:
    if n%3 == 0:
        ma = 2*(n/3) - (k-n/3)
    else:
        ma = 2*(n//3) - (k-n//3) + n%3
print("{} {}".format(mi,int(ma)))