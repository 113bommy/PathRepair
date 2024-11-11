t = input()
for _ in range(0,int(t)):
    s = input().split(" ")
    x = int(s[0])
    y = int(s[1])
    a = int(s[2])
    b = int(s[3])
    if((y-x)%(a+b)==0):
        print((y-x)/(a+b))
    else:
        print("-1")