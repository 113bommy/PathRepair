n = int(input())
now = input()
code = input()
count = 0
for i in range(n):
    if abs(int(now[i]) - int(code[i])) < abs(abs(int(now[i]) - int(code[i]) - 10)):
        count += abs(int(now[i]) - int(code[i]))
    else:
        count += abs(abs(int(now[i]) - int(code[i]) - 10))
print(count)