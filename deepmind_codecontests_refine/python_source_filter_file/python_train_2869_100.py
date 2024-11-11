import sys
n = int(input())
while n != 0:
    word = input()
    l = int(len(word))
    if len(word) < 10:
        print(word)
    else:
        first = word[0]
        mid = l - 2
        last = word[l-1]
        sys.stdout.write(str(first))
        sys.stdout.write(str(mid))
        sys.stdout.write(str(last))
        print("\n")
    n -= 1