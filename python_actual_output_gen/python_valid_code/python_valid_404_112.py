n = int(input())
in_user = []
count = 0
for i in range(n):
    s = input()
    in_user.append(s.split())
for j in in_user:
    if abs(int(j[0]) - int(j[1])) > 2:
        count += 1
print(count)