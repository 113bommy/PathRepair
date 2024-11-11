for t in range(int(input())):
    a, b, c=[int(i) for i in input().split()];j=0
    j=a//c
    if a==c or b==0:
        j=0
    elif b<j:
        j=b
    else:
        k=(b-j)//(c-1)
        if (b-j)%(c-1)!=0:
            k+=1
        j=j-(k)
    print(j)