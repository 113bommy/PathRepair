n = int(input())
str = input()
vowels = 'aeiou'
lst = []
for c in str:
    if c in vowels:
        if not lst or lst[-1] not in vowels:
            lst.append(c)
    else:
        lst.append(c)
print(''.join(lst))
