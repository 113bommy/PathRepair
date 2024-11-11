s = input()
answer = 0
for x in s:
    if x == '0' or x == '2' or x == '4' or x == '6' or x == '8' or x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u':
        answer += 1

print(answer)
