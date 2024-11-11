n = input()
a = sorted([int(i) for i in input().split()], reverse= True)

square_list = [i**2 for i in range(1,1001)]

for i in a:
    if i not in square_list:
        print(i)
        break