def main():
    number, times = input().split(' ')
    times = int(times)
    number = int(number)
    for i in range(times):
        if number % 10 != 0:
            number -= 1
        else:
            number = number / 10
    print(number)
main()

#s
