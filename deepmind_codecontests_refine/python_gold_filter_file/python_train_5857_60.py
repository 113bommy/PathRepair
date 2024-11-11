T = int(input())

def solve(n,r):
    

    if n<=r:
        if (n-1)%2 == 0:
            a = int((n-1))//2
            ret = int(a*n)+1
        else:
            a = int((n)//2)
            ret = int(a*(n-1))+1

    elif n>r:
        if (r+1)%2 == 0:
            a = int((r+1)/2)
            ret = int(a*r)
        else:
            a = int((r)//2)
            ret = int(a*(r+1))

    
    return ret


def solve2(n,r):
    ret = 1
    for k in range(2,r+1):
            if n>k:
               ret+=(k)

            else:
                ret+=1
                
                break
    return ret

while T>0:

    n,r = [int(el) for el in input().split(' ')]

    print(solve(n,r)) 

    T-=1
