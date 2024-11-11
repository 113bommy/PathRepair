n = int(input())
temp = 1

for number in sorted(map(int, input().split())):
    if number > temp:
        temp += 1

print(temp + 1)