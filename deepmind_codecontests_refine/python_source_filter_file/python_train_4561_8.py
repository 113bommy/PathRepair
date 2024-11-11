s = input()

s = s.replace('BC', 'D')
a_count = 0
count = 0
print(s)
for c in s:
    if c == 'A':
        a_count += 1
    elif c == 'D':
        count += a_count
    else:
        a_count = 0

print(count)