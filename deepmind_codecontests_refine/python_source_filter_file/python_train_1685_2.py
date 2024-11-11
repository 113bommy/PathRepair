w = int(input())
for x in range(w):
    c=0
    l=int(input())
    d = [int(x) for x in input().split(' ')]
#    d_c = sorted(d)
    min_p = d[-1]
    i=l-2
    while(i>=0):
        if(d[i]<min_p):
            min_p=d[i]
        else:
            c+=1
        i-=1
    print(c)