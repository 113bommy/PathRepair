n = int(input())
s = input()

br = False
br_index = -1
words = 0
words_in = 0

for i in range(n):
    if s[i] == '_':
        if i - br_index > 1:
            if not br:
                words = max(words, i - br_index - 1)
            elif br:
                words_in += 1
        br_index = i
    if s[i] == '(':
        if i - br_index > 1:
            words = max(words, i - br_index - 1)
        br_index = i
        br = True
    elif s[i] == ')':
        if i - br_index > 1:
            words_in += 1
        br_index = i
        br = False

if n - br_index > 1:
    words = max(words, i - br_index - 1)

print(words, words_in)
