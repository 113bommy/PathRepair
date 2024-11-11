import math
list = []
def printDivisors(n) :
    for i in range(1, int(math.sqrt(n) + 1)) :
        if (n % i == 0) :
            if (n / i == i) :
                list.append(i)
            else :
                list.append(i)
                list.append(int(n / i))
n,k=map(int,input().split())
printDivisors(n)
if(k>len(list)):
    print(-1)
else:
    list.sort()
    print(list[k-1])