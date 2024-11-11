starting = list(input().lower())
end_up = list(input())
print(starting)
string_output = []
count = 0
letter_dict = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8}

starting[1] = int(starting[1])
end_up[1] = int(end_up[1])
starting[0] = letter_dict[starting[0]]
end_up[0] = letter_dict[end_up[0]]

while starting[0] != end_up[0] or starting[1] != end_up[1]:
    if starting[0] > end_up[0]:
        starting[0] -= 1
        if starting[1] > end_up[1]:
            starting[1] -= 1
            string_output.append('LD')
        else:
            starting[1] += 1
            string_output.append('LU')
    else:
        starting[0] += 1
        if starting[1] > end_up[1]:
            starting[1] -= 1
            string_output.append('RD')
        else:
            starting[1] += 1
            string_output.append('RU')
    count += 1

while starting[0] != end_up[0] or starting[1] != end_up[1]:
    if starting[1] == end_up[1]:
        if starting[0] > end_up[0]:
            starting[0] -= 1
            string_output.append('L')

        else:
            starting[0] += 1
            string_output.append('R')

    else:
        if starting[1] > end_up[1]:
            starting[1] -= 1
            string_output.append('D')
        else:
            starting[1] += 1
            string_output.append('U')

    count += 1

print(count)
for i in string_output:
    print(i)
