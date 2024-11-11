from sys import stdin
from math import ceil, floor

doc = [line.strip() for line in stdin]
max_len = max(len(line) for line in doc)
counter = 0
print('*' * (max_len+2))
for line in doc:
    line_diff = (max_len-len(line))//2
    if (max_len-len(line)) % 2 != 0:
        counter = 1-counter
        pre_space, post_space = (line_diff+counter, line_diff+(1-counter))
    else:
        pre_space, post_space = (line_diff, line_diff)

    print('*' + ' ' * pre_space + line + ' ' * post_space + '*')

print('*' * (max_len+2))
