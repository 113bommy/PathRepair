string, n = str(input()), int(input())
if n > len(string):
    print("impossible")
else:
    freq = 26 * [0]
    letters = 0
    for j in range(len(string)):
        freq[ord(string[j]) - 97] += 1
        if freq[ord(string[j]) - 97] == 1:
            letters += 1
    print(n - letters)
