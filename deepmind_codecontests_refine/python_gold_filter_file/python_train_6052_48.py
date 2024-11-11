s = input()
zero, one = 0, 0

for si in s:
    if si=='0':
        print(1, zero%4+1)
        zero += 1
    else:
        print(4, one%2*2+1)
        one += 1