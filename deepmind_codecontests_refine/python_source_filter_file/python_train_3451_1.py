n = int(input())  # , m = [int(x) for x in input().split()]

def p2(n):
    return n != 0 and (((n - 1) & n) == 0)

c = 0
cc = 0
nums = []
tt = n
while not p2(n + 1):
    if c == 0:
       # print((2 ** (tt.bit_length())) - 1)
        n = n ^ ((2 ** (tt.bit_length())) - 1)
        nums += [tt.bit_length()]
        tt = int(tt**0.5)
    else:
        n += 1
    c = (c+1) % 2
    cc += 1

print(cc)
print(*nums)