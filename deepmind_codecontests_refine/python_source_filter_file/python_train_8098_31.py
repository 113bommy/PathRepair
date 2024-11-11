result = 0
for n in range(int(input())):
    result += len(n+1)%2
print(result)