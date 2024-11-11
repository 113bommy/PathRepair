def fun():
    a=[int(i) for i in input().split()]
    if(a.count(0)==5):
        return -1
    if(sum(a)%5==0):
        return (sum(a)/5)
    else:
        return (-1)
 
print(fun())