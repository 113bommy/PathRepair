import math
def function(n):
    if n==3:
        return 1
    if n%2==0:
        return int(n/2)
    for i in range(2, math.floor(math.sqrt(n))+1):
        if n%i==0:
            return int((n-i)/2)+1
    return 1




if __name__=="__main__":
    n=int(input())
    print(function(n))