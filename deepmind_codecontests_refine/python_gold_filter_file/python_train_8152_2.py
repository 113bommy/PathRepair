for i in range(int(input())):
    x=input()
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    e,f=map(int,input().split())
    if a!=c and b!=d:
        print(abs(a-c)+abs(b-d))
    elif a==c and b!=d:
        if a==e and ((f>b and f<d) or (f<b and f>d)) :
            print(abs(b-d)+2)
        else:
            print(abs(b-d))
    elif a!=c and b==d :
        if b==f and ((e>a and e<c) or (e<a and e>c)) :
            print(abs(a-c)+2)
        else:
            print(abs(a-c))
    else:
        print(0)