for _ in " " * int(input()):
    a,b=map(int, input().split())
    if a<b:a,b=b,a
    if a>2*b:print("NO")
    print('YNEOS'[((a+b)%3!=0)::2])