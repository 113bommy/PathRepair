for i in [0]*int(input()):
    a,b=map(int,input().split())
    print(['yes',*['nyoe s'[a==1 and b==1::2]]][a<=5 and 3*(a//2)<b])