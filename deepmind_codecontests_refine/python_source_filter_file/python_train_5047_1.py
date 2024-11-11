a,b = [int(x) for x in input().split()]
res = 0
while(a!=b ):
    if a % b == 0:
        res += int(a/b)
        break
    n = int(a//b)
    res += n
    atemp = a
    btemp = b
    a = btemp 
    b = atemp-n*btemp
    print("n=",n,sep=" ")

k = int(2//1)
print(res)