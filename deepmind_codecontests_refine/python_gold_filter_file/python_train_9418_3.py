s = list(map(int, list(input())))
n = len(s)
for i in range(n-1):
    if s[i] % 2 == 0 and s[i] < s[n-1]:
        s[n-1], s[i] = s[i], s[n-1]
        print(''.join(list(map(str, s))))
        exit()

for i in range(n-1, -1, -1):
    if s[i] % 2 == 0:
        s[n-1], s[i] = s[i], s[n-1]
        print(''.join(list(map(str, s))))
        exit()

print(-1)
    

