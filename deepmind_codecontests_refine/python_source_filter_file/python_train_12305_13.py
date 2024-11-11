import math

def find_good_number(n):
    
    current_good = 3**0
    k = 1
    while current_good < n:
        current_good += 3**k
        k += 1
    
    if current_good == n:
        return n
    
    power_to_start = int(math.log(current_good - n, 3))
        
    for i in reversed(range(power_to_start + 1)):
        diff = current_good - n
        if 3**i >= diff:
            continue
        current_good -= 3**i
        
    return current_good


if __name__ == '__main__':
    q = int(input())
    for _ in range(q):
        n = int(input())
        print(find_good_number(n))