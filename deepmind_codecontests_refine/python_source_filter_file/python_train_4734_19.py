from sys import exit
listofvowels = ["a", 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y']
listofletters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

sentence = input()

words = sentence.split()

def split(word):
    return [char for char in word]

words.reverse()
list = []
for i in range(len(words)):
    list.append(split(words[i]))
for i in range(len(words)):
    list[i].reverse()


for i in range(len(list) - 1):
    for j in range(len(list[i])):
        if list[i][j] in listofletters and list[i][j] in listofvowels:
            print("YES")
            exit(0)
        elif list[i][j] in listofletters and not list[i][j] in listofvowels:
            print("NO")
            exit(0)
        else:
            continue
