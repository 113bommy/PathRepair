question = input().strip()
vowels = 'AaEeIiOoUu'
lastchar = None
i = len(question) - 1
while i >= 0:
    if question[i] != '?' and question[i] != ' ':
        lastchar = question[i]
        break
    i -= 1

if lastchar in vowels:
    print('YES')
else:
    print('NO')
