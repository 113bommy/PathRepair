from fractions import gcd 

def find_LCM(x, y):
    return x * y // gcd(x, y)

def find_x_y(l, r):
    for iter_l in range(l, r + 1):
        for iter_r in range(iter_l + 1, r + 1):
            lcm = find_LCM(iter_l, iter_r)
            if l <= lcm and lcm <= r:
                return (iter_l, iter_r)
    return (-1, -1)
                

k = int(input())


for i in range(k):
    l, r = [int(i) for i in input().split()]
    
    #x, y = find_x_y(l, r)
    if 2 * l <= r:
        print("{} {}".format(l, 2*l))
    else:
        print('-1 -1')

    
    