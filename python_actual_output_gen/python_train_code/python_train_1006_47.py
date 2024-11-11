n = int(input())
word = []
for i in range(n):
    word.append(input())
    if  len(word[i]) >= 12:
     print(f"{word[i][0]}{len(word[i])-2}{word[i][-1]}")
    else:
        print(word[i])


