def getIntList():
    return list(map(int, input().split()));
n, k = getIntList();
p=getIntList();
choosed=[False]*256;
left=[i for i in range(256)];
for i, x in enumerate(p):
    if not choosed[x]:
        best=x;
        print(x-1, max(-1, x-k));
        for j in range(x-1, max(-1, x-k), -1):
            print('try ',j)
            if not choosed[j]:
                best=j;
            else:
                if x-left[j]<k:
                    best=left[j];
                break;
        print('best=',best)
        for j in range(best, x+1):
            choosed[j]=True;
            left[j]=best;
    p[i]=left[x];
print(' '.join(map(str, p)));