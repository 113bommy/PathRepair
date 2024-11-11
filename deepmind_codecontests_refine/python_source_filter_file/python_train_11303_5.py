n = int(input())
a = input()
cn = 0
fn = 0
tp = 0
c10p = 0
maxi = -1
while(len(a)!=0):
    maxi = -1
    for i in range(1,len(a)+1):
        ds = int(a[-i:])
        if(ds<n and int(a[-i])!=0):
            maxi = i

    if(maxi == -1 and a[-1] == 0):
        a = a[:-1]
        tp += 1
    else:
        fn += int(a[-maxi:])*n**tp
        tp += 1
        a = a[:-maxi]
print(fn)