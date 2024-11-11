s = input()
n = len(s)

if n % 2 == 0:
    print(s[n//2:].count('g') - s[:n//2].count('p'))
else:
    print(s[n//2+1:].count('g') - s[:n//2+1].count('p'))