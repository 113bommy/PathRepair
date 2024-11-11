d = input()
word = list(input())
chars = "qwertyuiopasdfghjkl;zxcvbnm,./"

for i in word:
    if d == 'R':
        index = chars.find(i) - 1
        print(chars[index], end='')
    else:
        index = chars.find(i) - 1
        print(chars[index], end='')