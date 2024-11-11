n, one,two,three = (int(x) for x in input().split())

n = n%4
if n == 3:
    print(min(one,3*three,two + three))
elif n == 2:
    print(min(2*one,two,2*three))
elif n == 1:
    print(min(3*one,two+one,three))
else:
    print(0)