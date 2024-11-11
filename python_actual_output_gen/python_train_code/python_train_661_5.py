s = input()
n = len(s) - s.count('a')

if n % 2:
    print(': (')
elif s[len(s) - n//2::] != s[0:len(s) - n//2].replace('a',''):
    print(': (')
else:
    print(s[0:len(s) - n//2])
