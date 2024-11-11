import math
def function(a, b):
    #if a==0 and b==0:
    #    return 'YES'
    #if a==b:
    #    return 'NO'
    #if a==0 or b==0:
    #    return 'NO'
    l=[a, b]
    a1=min(l)
    b1=max(l)
    #if (a+b)%3!=0:
    #    return 'NO'
    if 2*a >=b and (a+b)%3==0:
        return 'YES'
    return 'NO'



if __name__=="__main__":
    t=int(input())
    for k in range(t):
        a, b=map(int, input().rstrip().split())
        print(function(a, b))