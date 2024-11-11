import math
def get_smallest_divisor(n):
    if n <= 3:
        return n
    sqrt = int(math.sqrt(n))
    for i in range(2, sqrt):
        if n%i == 0 :
            return i
    return n
    

n_t = int(input())

for i in range(n_t):
    n, k = [int(x) for x in input().split()]

    if n % 2 == 0:
        print(f"{n + (2*k)}")
    else:
        sd = get_smallest_divisor(n)
        print(n + sd + (2*(k-1)))