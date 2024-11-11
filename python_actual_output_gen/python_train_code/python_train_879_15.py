n = int(input())
s = input()
result = 0
for i in range(len(s)-1,-1, -1):
    if int(s[i])%2==0:
        result += len(s)-i
print(result)
