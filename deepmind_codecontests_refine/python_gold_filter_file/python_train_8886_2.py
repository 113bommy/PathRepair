l = input()
line = input()

ans = 0
for i in range(len(line)):
    if i == 0:
        continue

    if line[i] == line[i-1]:
        ans+=1


print(ans)
