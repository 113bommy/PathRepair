abc = "abcdefghijklmnopqrstuvwxyz"
abc2 = abc + "a"
zyx2 = abc2[::-1]

t = int(input())
for query in range(t):
    s = input()
    odd = [letter for letter in s if ord(letter) % 2 == 1]
    even = [letter for letter in s if ord(letter) % 2 == 0]

    if len(odd) == 0 or len(even) == 0:
        print(s)
    
    else:
        odd.sort()
        even.sort()

        conect1 = odd[-1] + even[0]
        conect2 = even[-1] + odd[0]

        if conect1 not in abc2 and conect1 not in zyx2:
            print("".join(odd + even))
        elif conect2 not in abc2 and conect2 not in zyx2:
            print("".join(even + odd))
        else:
            print("No answer")



