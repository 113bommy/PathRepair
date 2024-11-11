def fuck(x):
    for i in range(1,99999):
        if i*i>=x:
            l = i-1
            x -= l*l
            if x<=l:
                return x,l+1
            else:
                return l+1,i*i-x-l*l+1


for i in range(0,int(input())):
    a,b = fuck(int(input()))
    print(a,b)