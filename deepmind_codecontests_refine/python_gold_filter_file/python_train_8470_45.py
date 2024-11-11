test = str(input())

for i in range(int(test) + 1, 10000):
    x = str(i)
    one = int(x[0])
    two = int(x[1])
    three = int(x[2])
    four = int(x[3])
    if one != two and one != three and one != four and two != three and two != four and three != four:
        print(x)
        break