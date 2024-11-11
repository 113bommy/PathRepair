n = int(input())
s = list(input())
d = s.count('D')
a = s.count('A')
if a > d :
    print('Anton')
elif d>a:
    print('Danik')
else:
    print('Friendship')
