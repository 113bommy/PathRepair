n = int(input())
l = input()
print('Anton' if l.count('A')> l.count('D') else 'Danik' if l.count('A') < l.count('D') else 'Friendship')