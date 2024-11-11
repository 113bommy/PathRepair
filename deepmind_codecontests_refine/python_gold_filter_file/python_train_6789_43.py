for _ in " "*int(input()):
    a,b=map(int,input().split());c=b;i=0
    while(c>0):c=c//10;i+=1
    i=i-(1 if str(b).count("9")!=len(str(b)) else 0)
    print(a*i)