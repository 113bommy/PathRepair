last = ''.join(input().split())
vowels = ['a', 'e', 'i', 'o', 'u', 'y']
if last[-2].lower() in vowels:
    print("Yes")
else:
    print("No")
