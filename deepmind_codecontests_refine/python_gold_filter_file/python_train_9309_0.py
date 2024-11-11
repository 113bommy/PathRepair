def possible(numbers):
        return int(numbers[0])//int(numbers[1])!=0 and int(numbers[0])%int(numbers[1])//(int(numbers[0])//int(numbers[1]))<=int(numbers[2])-int(numbers[1]) and int(numbers[0])%int(numbers[1])%int(numbers[0])//int(numbers[1])+int(numbers[0])%int(numbers[1])%(int(numbers[0])//int(numbers[1]))<=(int(numbers[2])-int(numbers[1]))*(int(numbers[0])//int(numbers[1])-int(numbers[0])//int(numbers[2]))
for i in range(0,int(input())):
    print('Yes' if possible(input().split(' ')) else 'No')
