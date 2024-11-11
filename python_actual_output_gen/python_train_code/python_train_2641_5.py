n=list(input())
if(len(n)==1):
    print(n[0])
else:
    counts=0
    while len(n)>1:
        s=0
        counts=counts+1
        for i in n:
            s=s+int(i)
        n=list(str(s))
    print(counts)