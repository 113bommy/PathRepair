n = int(input())
for _ in range(n):
    ln = int(input())
    num = input()
    num1 = int(num[:1])
    num2 = int(num[1:])
    if num1 < num2:
        print("YES\n",end='')
        print(num1, num2)
    else:
        print("NO")
