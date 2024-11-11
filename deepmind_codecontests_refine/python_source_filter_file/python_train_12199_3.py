string = str(input())
substring = str(input())

len_string = len(string)
len_substring = len(substring)
minimal_string_pos = []
max_string_pos = []
sub_flag = 0

for i in range(len_string):
    if string[i] == substring[sub_flag]:
        minimal_string_pos.append(i)
        sub_flag += 1
        if sub_flag > len_substring - 1:
            break

sub_flag = len(substring) - 1
for i in range(len_string - 1, -1, -1):
    if string[i] == substring[sub_flag]:
        max_string_pos.append(i)
        sub_flag -= 1
        if sub_flag < 0:
            break

max_string_pos = max_string_pos[::-1]
digit_max_1 = max(max_string_pos[0], len_string - (minimal_string_pos[len(minimal_string_pos) - 1] + 1))
digit_max_2 = 0

for i in range(len(substring) - 1):
    digit_max_2 = (max_string_pos[i + 1] - minimal_string_pos[i] - 1 if max_string_pos[i + 1] - minimal_string_pos[i] - 1 > digit_max_2 else digit_max_2)

print(max(digit_max_1, digit_max_2 - 1))
