n,k = map(int,input().split())
s = input()
c = list(input().split())
set(c)
answer = 0
i = 0
while True:
    if i >= n:
        break
    j = i

    while (j < n and c.count(s[j])):
        j += 1

    answer += ((j - i) * (j - i + 1)) // 2
    i = j
    i+=1
print(answer)
