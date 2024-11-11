str = int(input())

while str >= 1:
    word = input()
    str -= 1
    length = len(word)

    if 1 <= length <= 100:
        if length > 10:
            print(word[0],(length - 2),word[-1])
        elif length < 10:
            print(word)