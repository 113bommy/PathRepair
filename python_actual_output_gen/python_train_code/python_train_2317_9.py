n = int(input())
for i in range(n):
    num = input()
    s = num[0]
    digit = len(num)
    if digit == 2 :
        print(int(s)*10 - 7)
    elif digit == 3 :
        print(int(s)*10 - 4)
    elif digit == 4:
        print(int(s)*10 + 4)
    else :
        print(int(s)*10 -9)
