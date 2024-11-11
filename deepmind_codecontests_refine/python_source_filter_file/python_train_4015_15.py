t = int(input())
s = input().replace('W', ' ').split()
print(s)
print(len(s))
for i in s:
    print(len(i), end= ' ')