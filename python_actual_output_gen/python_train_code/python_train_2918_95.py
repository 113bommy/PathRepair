red, blue = map(int, input().split(" "))
one = 0
two = 0
while red != 0 and blue != 0:
    if red and blue:
        red -= 1
        blue -= 1
        one += 1
while red >= 2:
    red -= 2
    two += 1
while blue >= 2:
    blue -= 2
    two += 2
print(str(one) + " " + str(two))