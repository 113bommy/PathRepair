n = int(input())

zero = 0
ones = 1023

for _ in range(n):
    op, num = input().split()
    
    num = int(num)
    
    if op == '&':
        zero &= num
        ones &= num
    elif op == '|':
        zero |= num
        ones |= num
    else:
        zero ^= num
        ones ^= num

and_bits = 0
or_bits  = 0
xor_bits = 0

for i in range(10):
    z = (zero >> i) & 1
    o = (ones >> i) & 1
    
    if z == 0 and o == 0:
        and_bits |= 0 << i
        or_bits  |= 0 << i
        xor_bits |= 0 << i
    elif z == 0 and o == 1:
        and_bits |= 1 << i
        or_bits  |= 0 << i
        xor_bits |= 0 << i
    elif z == 1 and o == 0:
        and_bits |= 1 << i
        or_bits  |= 0 << i
        xor_bits |= 1 << i
    else:
        and_bits |= 1 << i
        or_bits  |= 1 << i
        xor_bits |= 0 << i

print(3)
print('& {}'.format(and_bits))
print('| {}'.format(or_bits))
print('^ {}'.format(xor_bits))