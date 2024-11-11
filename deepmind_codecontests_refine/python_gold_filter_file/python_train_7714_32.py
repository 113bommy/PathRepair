l,r = map(int,input().split())
if ((r-l)%2 == 0):
    print ("NO")
else:
    print ("YES")
    while (l<r):
        print (l,l+1)
        l = l+2
