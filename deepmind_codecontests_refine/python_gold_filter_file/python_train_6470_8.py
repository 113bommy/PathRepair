#1155B
n= int(input())
s = [int(x) for x in input()]
s = s[:-10]
if s.count(8) > (n-11)//2:
    print('YES')
else:
    print('NO')
