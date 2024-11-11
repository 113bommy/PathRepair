#!/usr/bin/env python3

def is_prime(p):
    for i in range(3, p):
        if p % i == 0:
            return False
    return True

def next_prime(k):
    result = k+1
    while not is_prime(result):
        result += 1
    return result

def check_noldbach(n, k):
    count = 0
    p1 = 3
    p2 = 5
    while (p1 + p2 + 1 < n):
        #  print('Checking pair: ' + str(p1) + ' ' + str(p2), end = ' ')
        if is_prime(p1 + p2 + 1):
            #  print('Good pair')
            count += 1
        #  else:
            #  print('')
        p1 = p2
        p2 = next_prime(p2)
    if count >= k:
        return True
    else:
        return False

def main():
    n, k = [int(j) for j in input().split(' ')]
    if check_noldbach(n, k):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
