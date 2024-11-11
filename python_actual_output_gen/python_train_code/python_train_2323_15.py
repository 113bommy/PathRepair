n = int(input()[-2:])
#n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
k = 1
i = 0
while k and i < n:
    if s[i] != '1':
        k = 0
    i += 1
print(i) 