# cook your dish here
for _ in range(int(input())):
    n = int(input())
    num = n - 1
    if num % 2 == 0:
        print(num//2,num)
    else:
        num = num - 1