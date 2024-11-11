n = input()
num = int(n) + 1
while num <= 10000:
    var = str(num)
    c1 = var.count(var[0])
    c2 = var.count(var[1])
    c3 = var.count(var[2])
    c4 = var.count(var[3])
    #print(num, c1, c2, c3, c4, var)
    if c1 == 1 and c2 == 1 and c3 == 1 and c4 == 1:
        print(var)
        break
    num += 1