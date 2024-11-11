t=int(input(""))
i=0
k=0
while k<t:
    x,y=[int(x) for x in input().split()]
    while y>i*(i+1)/2:
        i+=1
    print("a"*int(x-i-1)+"b"+"a"*int((i+1)*i/2-y)+"b"+"a"*int(x-2-(x-i-1)-((i+1)*i/2-y)))
    k+=1
