blue = [input() for i in range(int(input()))]
red = [input() for i in range(int(input()))]
print(max(0, [blue.count(i) - red.count(i) for i in set(blue + red)]))