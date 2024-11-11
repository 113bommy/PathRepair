for _ in range(int(input())):
    r,g,b=map(int,input().split())
    if r>=b and r>=g and r<=b*g+1:
        print('Yes')
    elif b>=r and b>=g and b<=r*g+1:
        print('Yes')
    elif g>=b and g>=r and g<=b*r+1:
        print('Yes')
    else:
        print('No')