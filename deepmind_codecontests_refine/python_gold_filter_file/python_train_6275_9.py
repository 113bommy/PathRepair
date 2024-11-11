import math
def function(n):
    total=0
    min1=10**10
    if n==1:
        return 0
    if n==2:
        return 1
    if n==3:
        return 2
    for i in range(math.floor(math.sqrt(n)), 0, -1):
        c=(i-1)+(math.ceil(n/i)-1)
        if c<min1:
            min1=c
            total+=1
        if c>min1:
            return (min1)
            break
        #print(f'total, c: {total}, {c}')
function(3)
if __name__=="__main__":
    t=int(input())
    for k1 in range(t):
        n=int(input())
        print(function(n))
        #print('----')