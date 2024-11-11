

n = int(input())
words = []
for i in range(n):
    words.append(input())
words.sort(key=len)
r = True
for i in range(n-2, -1, -1):
    if words[i] not in words[i+1]:
        r = False
        break
if r:
    print("Yes")
    for i in range(n):
        print(words[i])
else:
    print("No")
