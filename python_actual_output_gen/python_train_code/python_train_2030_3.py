n = int(input())
ans = 0
data = input()
code = input()
for i in range(n):
    ans += abs(5 - abs(int(data[i]) - (int(code[i]) + 5)%10))
    print(ans)
