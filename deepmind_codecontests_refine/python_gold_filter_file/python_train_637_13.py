from sys import stdin, stdout

n, m = [int(x) for x in stdin.readline().rstrip().split()]
chests = [int(x) for x in stdin.readline().rstrip().split()]
keys = [int(x) for x in stdin.readline().rstrip().split()]

odd_chests = 0
odd_keys = 0
even_chests = 0
even_keys = 0
for chest in chests:
    if chest % 2 == 1:
        odd_chests += 1
    else:
        even_chests += 1
for key in keys:
    if key % 2 == 1:
        odd_keys += 1
    else:
        even_keys += 1

result = min(odd_chests, even_keys)
result += min(odd_keys, even_chests)
stdout.write(str(result) + "\n")