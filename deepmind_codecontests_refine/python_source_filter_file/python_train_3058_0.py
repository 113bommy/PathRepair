def num(a,b,n):
    for i in "0123456789":
        if int(a+i) % b == 0:
            a = a + i
            break
    else:
        return -1
    return a + "0"*n-1
a,b,n = input().split()
print(a,int(b),int(n))