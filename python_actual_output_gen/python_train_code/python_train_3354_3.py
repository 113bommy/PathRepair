n = int(input())
min1,max1 = map(int, input().split())
min2,max2 = map(int, input().split())
min3,max3 = map(int, input().split())
a = min1
b = min2
c = min3
n -= (c + b + a)
if n>0 :
    if (max3 - min3) > n:
        c += n
    else:
        c = max3
        n -= (max3 - min3)
        if (max2 - min2) > n:
            b += n
        else:
            b = max2
            n -= (max2 - min2)
            a += n
print(a,b,c)



