n = int(input())
a = []
army = 0
words = input().split()
for i in range(n):
    s = list(set(words[i]))
    if s not in a:
        army += 1
        a.append(s)
print(army)
