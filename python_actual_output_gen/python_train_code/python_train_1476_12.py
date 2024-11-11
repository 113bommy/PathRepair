s = input()

l = 0
r = len(s) - 1
answer = 0

while l != r:
    if s[l] == s[r]:
        l += 1
        r -= 1
    elif s[l] == 'x':
        l += 1
        answer += 1
    elif s[r] == 'x':
        r -= 1
        answer += 1
    else:
        print(-1)
        exit()

print(answer)