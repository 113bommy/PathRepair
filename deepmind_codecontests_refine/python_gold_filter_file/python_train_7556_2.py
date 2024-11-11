x = input()

if int(x)<10:
    print (1)
elif (int(x)%(10**len(x)))==0:
    print (x)
else:
    l=len(x)
    x=int(x)
    s=(10**(l-1))-(x%(10**(l-1)))
    print(s)