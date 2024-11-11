text = input()
answer = 0
check = 'a'
for i in text:
    answer += min(abs(ord(i)-ord(check)),26-abs(ord(i)-ord(check)))
    p =i
print(answer)