number = int(input())
for i in range(number):
    word = input("")
    length = len(word)
    if length<10:
        print(word)
    if length>=10:
        print(word[0]+str(len(word)-2)+word[-1])
