n = int(input())
s = input()
cont = 0
for i in range(1, n):
    if s[i] == s[i-1]:
        cont += 1
print(cont)