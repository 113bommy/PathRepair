def get_next_char(char):
    return "a" if char == "z" else chr(ord(char) + 1)

string_array = []
string_array.extend(input())           

for i in range(1,len(string_array)-1):
    char = string_array[i]    
    prev_char = string_array[i-1]
    next_char = string_array[i+1]
    if char == prev_char:
        # z back to a
        char = get_next_char(char)
        if char == next_char:
            char = get_next_char(char)
        string_array[i] = char

if len(string_array) >= 2 and string_array[-1] == string_array[-2]:
    string_array[-1] = get_next_char(string_array[-1])

answer = ''
for i in string_array:
    answer += i
print(answer)