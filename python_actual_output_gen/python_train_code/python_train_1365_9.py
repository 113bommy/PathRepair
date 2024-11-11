s1 = input()
s2 = input()

vowels = {'a', 'e', 'i', 'o', 'u'}
if len(s1) != len(s2):
    print("No")
else:
    for i, j in zip(s1, s2):
        if (i in vowels and j in vowels) or (i not in vowels and j not in vowels):
            continue
        else:
            print("No")
            exit()
print("Yes")




