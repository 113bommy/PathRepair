def can_be_telephone(number):
    for i in range(len(number)):
        if number[i] == '8' and i <= len(number) - 10:
            return True
    return False

for _ in range(int(input())):
    n = input()
    number = input()
    print("YES" if can_be_telephone(number) else "NO")