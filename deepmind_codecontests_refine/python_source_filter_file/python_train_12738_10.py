n = int(input())
p = [i for i in range(n)]
if(n==1) :
    print(-1)
else :
    for i in range(1,n) :
        if(i%2!=0) :
            temp = p[i];p[i] = p[i-1];p[i-1] = temp 
    for i in range(n) :
        print(p[i]+1,end=' ')
    print()