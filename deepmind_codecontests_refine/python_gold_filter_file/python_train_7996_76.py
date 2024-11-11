s = input()
k = int(input())
for a in s[:k]:
    if a != '1':
        print(a)
        exit()
print('1')