for i in range(int(input())):
    a,b,c,d=map(int,input().split())
    rem=a%2+b%2+c%2+d%2
    print("No" if( rem ==2 or rem>2) and a*b*c==0 else "Yes" )