import string

num: int = eval(input())
for num in range (1,num):

    word: string = input()

    if len(word) <= 10:
        print(word)
    else:
        print(word[0]+ str(len(word)-2) + word[len(word)-1])