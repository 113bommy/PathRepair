n = input()
for i in range(len(n)-1,-1,-1):
    dig = int(n[i])
    if dig // 5:
        print("-0|",end="")
    else:
        print("0-|",end="")
    print('0' * (dig % 5) + '-' + '0' * (4 - dig % 5))
