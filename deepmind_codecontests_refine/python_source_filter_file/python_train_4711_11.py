def myfunction(nnn):
    answet=[]
    for i in range(1,len(nnn)):
        demo1=nnn[0:i]
        demo2=nnn[i:len(nnn)]
        answet.append(abs(max(demo1)-min(demo2)))
    print(min(answet))
n=int(input())
for i in range(n):
    nn=int(input())
    nnn=[*map(int,str(input()).split(' '))]
    bb=[myfunction(nnn)]
    if nn==len(bb):
        for i in bb:
            print(bb)
