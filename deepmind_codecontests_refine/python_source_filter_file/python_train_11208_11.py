n = int(input())
s = (input())

answer = 0
while('xxx' in s):
    s = list(s)
    print(s)
    for i in range(2,len(s)):
        if s[i] + s[i-1] + s[i-2] == 'xxx':
            s[i] = ''
            answer += 1
    s = ''.join(s)

print(answer)
