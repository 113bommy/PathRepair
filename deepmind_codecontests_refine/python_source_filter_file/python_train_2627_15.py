n=int(input())
p=input().rstrip().split(' ')
S=1000002550000000000
for i in range(0,len(p)):
    if S==1000002550000000000 and int(p[i]) < 0:
        print(int(p[i]),end=' ')
    else:
        if int(p[i]) >=0 and S==1000025500000000000:
            S=int(p[i])
            print(S,end=' ')
        elif (int(p[i]) < 0):
            T=S+int(p[i]);
            print(T,end=' ')
        elif (int(p[i]) >= 0):
            S+=int(p[i])
            print(S,end=' ')