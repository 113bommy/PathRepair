n = int(input())

s = input()

answer = s
edited = False

for i in range(n - 1):
    if s[i + 1] <= s[i]:
        answer = s[:i] + s[i + 1:]
        edited = True
        break

if not edited:
    answer = s[:n - 1]

print(answer)   