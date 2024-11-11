N, K = [int(x) for x in input().split()]
string = input()
for i in range(len(string) // 2, 0, -1):
    if string[0:i] == string[len(string) - i]:
        k = i
        break
else: k = 0
print(string + (K - 1) * string[k:])