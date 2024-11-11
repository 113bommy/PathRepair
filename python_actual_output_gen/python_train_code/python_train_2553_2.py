n = int(input())
pi = [int(input()) for i in range(n)]
ans = 1
for i in range(n):
    if pi[i] == -1:
        continue
    num = pi[i]
    temp = 1
    while pi[num-1] != -1:
        temp += 1
        num = pi[num-1]
    ans = max(ans,temp)
print(ans)
