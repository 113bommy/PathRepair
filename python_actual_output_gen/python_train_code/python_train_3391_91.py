n = int(input())
l = input().split()
print('Anton' if l.count('A')> l.count('D') else 'Danik' if l.count('A') < l.count('D') else 'Friendship')