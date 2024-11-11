letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
n = int(input())
result = ["" for i in range(n)]

for i in range(n):
    strings = input().lower()
    coding = [0 for k in range(len(strings))]
    for index, letter in enumerate(strings):
        if letters.index(letter) not in coding:
            coding[index] = letters.index(letter)
    coding.sort()
    if 0 in coding:
        result[i] = "No"
    elif coding[-1] - coding[0] == len(strings) - 1:
        result[i] = "Yes"
    else:
        result[i] = "No"

for outp in result:
    print(outp)
