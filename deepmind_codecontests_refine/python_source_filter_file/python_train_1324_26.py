s = input().split(' ')
a = int(s[0])
b = int(s[1])
dic = {1 : '1', 2 : '5/6', 3 : '2/3', 4 : '1/2', 5 : '1/3', 6 : '1/6'}
if a >= b:
    print(dic[a])
else:
    print(dic[b])