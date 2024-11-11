text = input()
answer = 0
check = 'a'
for i in text:
    answer += min(ord(i)-ord(check),26-(ord(i)-ord(check)))
    check =i
print(answer)