n = int(input())
answer = 0
for i in range(1,n+1):
    answer += 2 ** i
print(answer)