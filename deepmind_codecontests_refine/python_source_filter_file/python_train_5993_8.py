n = int(input())

s = input()

parentheses = 0
par_arr = []
max_length = 0
in_vocab = 0

words = []

j = 0

for i, k in enumerate(s):
    if k == '_':
        words.append(s[j:i])
        j = i + 1
        par_arr.append(parentheses)
        continue
    elif k == '(':
        words.append(s[j:i])
        j = i + 1
        par_arr.append(parentheses)
        parentheses += 1
        continue
    elif k == ')':
        words.append(s[j:i])
        j = i + 1
        par_arr.append(parentheses)
        parentheses -= 1
        continue
    else:
        pass

words.append(s[j:i])
j = i + 1
par_arr.append(parentheses)
parentheses += 1

for i in range(len(words)):
    if par_arr[i] == 0:
        max_length = max(max_length, len(words[i]))
        continue
    else:
        if len(words[i]) > 0:
            in_vocab += 1

print(max_length, in_vocab)
