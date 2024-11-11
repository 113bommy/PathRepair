s = input()
k = int(input())
chars = set()
for c in s:
    chars.add(c)
if k > len(s):
    print('impossible')
else:
    diff = k - len(chars)
    print('diff') if diff > 0 else print('0')