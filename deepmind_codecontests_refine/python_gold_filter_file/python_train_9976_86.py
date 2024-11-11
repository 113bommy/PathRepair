n = int(input())

ans = []
for j in range(2,11):
    l = [i**j for i in range(1,32) if i**j <= n]
    ans = ans + l
print(max(ans))