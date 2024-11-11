total = int(input())
letters = input()

zes = 0
zeroes = 0
for i in letters:
    if i == 'o':
        zeroes += 1
    if i == 'z':
        zes += 1
        
zero = zes
one = zeroes - zes

result = ''
for k in range(one):
    result += '1'
for j in range(zero):
    result += '0'
    
print(result)