n,h,a,b,k=map(int,input().split())
for i in range(k):
    ta,fa,tb,fb=map(int,input().split())
    if ta==tb:
        print(abs(fa-fb))
    elif fa>=a and fb<=b:
        print(abs(ta-tb)+abs(fb-fa))
    elif abs(fa-a)<abs(fa-b):
        print(abs(fa-a)+abs(ta-tb)+abs(fb-a))
    else:
        print(abs(fa-b)+abs(ta-tb)+abs(fb-b))