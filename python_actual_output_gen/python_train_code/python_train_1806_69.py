n = int(input())
sauce = [0,4,4,4,4,4,4,4,4,4,15, 1]
ind = n - 10
if ind < len(sauce) and ind >= 0:
    print(sauce[ind])
else:
    print(0)