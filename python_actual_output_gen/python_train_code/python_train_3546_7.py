n = int(input())
list = [ int(i) for i in input().split() ]

for i in range(len(list)):
    if list[-1] != list[-i]:
        print(len(list) - i + 1)
        break