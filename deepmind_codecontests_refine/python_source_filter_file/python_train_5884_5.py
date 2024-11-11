#!/usr/bin/env python3

def isPow2(v):
    return (v & (v - 1)) == 0

def roundUpToHole(n):
    next_pow_2 = 2**(n.bit_length()) - 1
    rem = next_pow_2 - n

    if rem == 0:
        return n + (next_pow_2+1) - (next_pow_2+1) // 2

    rem2 = 2**(rem.bit_length()-1)
    n2 = next_pow_2 - rem

    return n2


a, b = map(int, input().split())

i = roundUpToHole(a)
bitlen = i.bit_length()

count = 0
while i <= b:
    #print(':', i, bin(i))
    count += 1

    next_pow_2 = 2**bitlen - 1
    rem = next_pow_2 - i
    #assert isPow2(rem)
    if rem > 1:
        i += rem
        i -= rem // 2
    elif rem == 1:
        #print('darn', i, rem, next_pow_2)
        i += rem
        i += (next_pow_2+1)
        i -= (next_pow_2+1)//2
        #print('darn2', i)
        bitlen += 1
    else:
        assert False

print(count)
