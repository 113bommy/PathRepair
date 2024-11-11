s = input()
print('Second' if len(s) % 2 == 0 ^ s[0] != s[-1] else 'First')
