from fractions import Fraction as f

inps = list(map(int,input().split()))
a,b,c,d = inps[0],inps[1],inps[2],inps[3]


if (a/b < c/d):
    print(f((b*c)-(a*d),b*c))
elif (a/b > c/d):
    print(f((a*d)-(b*c),a*d))
else:
    print("0")
