x1 = int(input())
x2 = int(input())
x3 = int(input())
x4 = int(input())

i = str(x1)+str(x2)+str(x3)+str(x4)


o1 = 1 if x1 | x2 == 0 else 0
r1 = 1 if x3 ^ x4 == 1 else 0
a1 = 1 if x2 & x3 == 0 else 0
o2 = 1 if x1 | x4 == 1 else 0

a10 = 1 if o1 & r1 == 0 else 0
r10 = 1 if a1 ^ o2 == 1 else 0

ans = 1 if a10 | r10 == 0 else 0

# print(ans)

if   i == '0000': print(0)  # +
elif i == '0001': print(1)  # +
elif i == '0010': print(0)  # +
elif i == '0011': print(1)  # 11
elif i == '0100': print(0)  # +
elif i == '0101': print(0)  # 11
elif i == '0110': print(0)  # +
elif i == '0111': print(1)  # 11
elif i == '1000': print(1)  # +
elif i == '1001': print(1)  # +
elif i == '1010': print(0)  # +
elif i == '1011': print(1)  # ?8
elif i == '1100': print(1)  # +
elif i == '1101': print(0)  # ?8
elif i == '1110': print(1)  # +
elif i == '1111': print(0)  # ?11



