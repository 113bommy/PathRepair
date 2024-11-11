import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
print(a)

counter = 0


for k in a:
    breaker = 0
    counter = 0
    for i in range(1, 10, 1):
        if breaker == 0:
            for j in range(1, 5, 1):
                if breaker == 0:
                    counter += j
                    if (str(k)[0] == str(i)) and j == len(str(k)):
                        print(counter)
                        breaker = 1
                else:
                    break
        else:
            break
