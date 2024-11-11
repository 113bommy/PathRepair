css = int(input())
for _ in range(css):
    inputSet = [int(num) for num in input().split()]
    n, m = inputSet[:2]
    rb, cb = inputSet[2:4]
    rd, cd = inputSet[4:]
    verticalCost = rd-rb if rd>=rb else n-cb + n-cd
    horizontalCost = cd-cb if cd>=cb else m-rb + m-rd
    print(min(verticalCost, horizontalCost))