def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split()))

def fact(n,i):
    if(n == 1 or n == 0):
        return 1
    elif(n == i):
        return i
    else:
        return n * fact(n-1,i)

n = inp()

half_group_ways = fact(n,n/2+1)/fact(n/2,1)
#print(half_group_ways)
group_order = fact(n/2,1)/(n/2)
#print(group_order)
print(int(half_group_ways * group_order * group_order /2))
