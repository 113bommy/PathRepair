n = int(input())
c = input()
if c.count('A') > c.count('D'):
    print('Anton')
elif c.count('A') < c.count('D'):
    print('Danik')
else:
    print('Friendship')
