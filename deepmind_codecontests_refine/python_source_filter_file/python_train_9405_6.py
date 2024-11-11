import string
Alphabets = string.ascii_uppercase
def int2word(y):
    z = ""
    while y > 0:
        k = y % 26
        if k == 0:
            y -= 1
        z += Alphabets[int(k) - 1]
        y = y // 26 
    return z[::-1]
def word2int(y):
    z = 0
    for i in range(len(y) - 1, -1, -1):
        z += int(Alphabets.index(y[len(y) - i - 1]) + 1) * (26 ** i)
    return str(z)

def type1(l):
    num1 = ""
    num2 = ""
    for j in cell:
        try:
            num1 += str(int(j))
        except:
            num2 += j
    print("R" + num1 + "C" + word2int(num2))

length = int(input())
for i in range(length):
    cell = input()
    if "R" in cell and "C" in cell and "R" == cell[0] and "C" != cell[1]:
        num = ""
        for j in range(1, len(cell)):
            if cell[j] == "C":
                x = num
                num = ""
            elif "0" <= cell[j] <= "9":
                num += cell[j]
        try:
            x = str(int(num))
            print(int2word(int(num)) + str(x))
        except:
            type1(cell)
    else:
        num1 = ""
        num2 = ""
        for j in cell:
            try:
                num1 += str(int(j))
            except:
                num2 += j
        print("R" + num1 + "C" + word2int(num2))