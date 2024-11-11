a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = a*1000+b*100+c*10+d
if s == 0:
    print(0) #OK2
elif s == 1:
    print(1)#OK9
elif s == 10:
    print(0)#OK6
elif s == 11:
    print(1)#OK13
elif s == 100:
    print(0)#OK4
elif s == 101:
    print(0)#OK11
elif s == 110:
    print(0)#OK1
elif s == 111:
    print(1)#OK16
elif s == 1000:
    print(1)#OK3
elif s == 1001:
    print(1)#OK10
elif s == 1010:
    print(0)#OK7
elif s == 1011:
    print(1)#14
elif s == 1100:
    print(1)#OK5
elif s == 1101:
    print(0)#OK12
elif s == 1110:
    print(1) #OK8
elif s == 1111:
    print(0)#15
else:
    print(0)