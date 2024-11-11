n,x,y=list(map(int,input().split()))
sam=(y/100)*n
if int(sam)==sam:
    if x>=sam:
        print(0)
    else:
        print(sam-x)
else:
    sam=int(sam)+1
    if x>=sam:
        print(0)
    else:
        print(sam-x)