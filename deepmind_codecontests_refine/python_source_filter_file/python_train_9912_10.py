for i in range(int(input())):
    a,b=map(int,input().split())
    x=[int(q) for q in input().split()]
    
    j=0
    for i in range(a):
        if x[i]>x[j]:
            j=i
        b-=x[i]
        if b<0:
            break
    if b>=0:
        j-=1
    print(j+1)