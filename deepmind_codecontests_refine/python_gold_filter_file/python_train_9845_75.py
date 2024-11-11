n = int(input())
w = input()
if w.count('A') > w.count('D'):
    print('Anton')
elif w.count('A') < w.count('D'):
    print('Danik')
else:
    print('Friendship')