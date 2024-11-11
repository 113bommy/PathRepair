n = int(input())

cards_b = input().split()
cards_s = list(cards_b)

# BubbleSort
for i in range(n):
    for j in range(n - 1, i, -1):
        if int(cards_b[j][1]) < int(cards_b[j - 1][1]):
            cards_b[j], cards_b[j - 1] = cards_b[j - 1], cards_b[j]

#SelectionSort
for i in range(n):
    min_i = i
    for j in range(i, n):
        if int(cards_s[j][1]) < int(cards_s[min_i][1]):
            min_i = j
    cards_s[i], cards_s[min_i] = cards_s[min_i], cards_s[i]

print(" ".join(cards_b))
print("Stable")
print(" ".join(cards_s))

if cards_b == cards_s:
    print("Stable")
else:
    print("Not stable")