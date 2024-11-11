from sys import stdin, stdout
s = stdin.read()
ans = 0
even = set('02468')
vowel = set('aeiou')
for c in s:
    if c in vowel:
        ans += 1
    if c in even:
        ans += 1
stdout.write('{}\n'.format(ans))