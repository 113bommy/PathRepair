s = input()
k = int(input())

for k_i in range(k):
    if s[k_i] != "1":
        print(s[k_i])
        exit()
print(1)