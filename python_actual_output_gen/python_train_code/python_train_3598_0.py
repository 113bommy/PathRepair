
x = 'ares'

rotations_count = 0
cur_position = ord('a')

for i, next_chr in enumerate(x):
    next_pos = ord(next_chr)
    straight = abs(next_pos - cur_position)
    left = cur_position - ord('a') + ord('z') - next_pos + 1
    right = ord('z') - cur_position + next_pos - ord('a') + 1
    rotations_count += min([straight, left, right])
    cur_position = next_pos

print(rotations_count)