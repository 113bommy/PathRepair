n=input()
i=n
while True:
    i=str(i)
    alist=list(i)
    length=len(alist)
    t=True
    for x in alist :
        if alist.count(x)!=1 :
            t=False
    if t==True:
        print(i)
        break
    else:
        i=int(i)
        i+=1