c = int(input())
a = []
for i in range(c):
    x=int(input())
    a = list(map(int,input().split()))[:]
    p = sorted(a)
    if(x==1):
        print(1)
        break
    else:
        for j in range(1,x):
            if((p[j]-p[j-1])==1):
                print(2)
                m = 0
                break
            else:
                m = 1
    if(m==1):
        print(1)


