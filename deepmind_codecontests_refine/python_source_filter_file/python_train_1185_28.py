a,b,c,d = [int(x) for x in input().split()]
p1 = 1-(a/b)
p2 = 1-(c/d)
p = (a/b)/(a-p1*p2)
print (p)