import sys

hp = int(sys.stdin.readline())

def get_categ(nb):
    if nb % 4 == 0:
        return 3
    elif nb % 4 == 2:
        return 2
    elif nb % 4 == 3:
        return 1
    elif nb % 4 == 1:
        return 0


arr = [1, 2, 3]
for i in range(0, 2):
    arr[i] = get_categ(hp + i)

categ = "ABCD"
letter_num = min(arr)

letter = categ[letter_num]
digit = arr.index(letter_num)

print(digit, letter)

