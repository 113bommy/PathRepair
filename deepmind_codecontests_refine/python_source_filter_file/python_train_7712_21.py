n = int(input())
a = list(map(int,input().split()))
p = n // 2 
if sum(a[:p]) == sum (a[p :]) :
    print(sum (a [:p]))
elif  sum (a[:p +1]) == sum (a[p+1 :]) :    
    print(sum(a[ :p +1]))
else :    
    li, ri, aix, ls, rs = 0, n , 0, 0, 0
    while li < ri :
        if ls < rs :
            li += 1
            ls += a[li]
        elif ls > rs :
            ri -= 1
            rs += a[ri]
        else :
            aix = li
            li += 1
            ri -= 1 
            ls += a[li]
            rs += a[ri]       
    print(sum(a[:aix]))