def get_color(left, right):
    if right is None:
        if left == 'R':
            return 'G'
        elif left == 'G' or left == 'B':
            return 'R'
    else:
        if left == 'G' and right == 'G':
            return 'R'
        elif (left == 'R' and right == 'G') or (left == 'G' and right == 'R'):
            return 'B'
        elif (left == 'G' and right == 'B') or (left == 'B' and right == 'R'):
            return 'R'
        else:
            return 'G'


n = int(input())
s = list(input())
i, r = 0, 0

while i < len(s) - 1:
    if s[i] == s[i + 1]:
        r += 1
        s[i + 1] = get_color(s[i], s[i + 2] if i < len(s) - 2 else None)
        i += 2
    else:
        i += 1


print(r)
print(''.join(s))