n = int(input())
b = [int(x) for x in input().split(" ")]
output = [0] * (400000)
for i in range(n):
    output[b[i] - (i + 1)] += b[i]
print(max(output))


# import random
# file = open("m", 'w')
# adding = 50
# subtraction = 50
# multiplication = 30
# division = 30
# power2 = 20
# power3 = 10
# file.write("add: \n\n")
# file.write("--------------------------------------------------\n")
# for j in range(adding):
#     first = random.randint(1, 999)
#     second = random.randint(1, 999)
#     file.write("(%s)\t%s + %s\n---------------------\n" %(j + 1, first, second))
# file.write("subtraction: \n\n")
# file.write("--------------------------------------------------\n")
# for j in range(subtraction):
#     first = random.randint(1, 999)
#     second = random.randint(1, 999)
#     file.write("(%s)\t%s - %s\n---------------------\n" %(j + 1, first, second))
# file.write("multiplication: \n\n")
# file.write("--------------------------------------------------\n")
# for j in range(multiplication):
#     first = random.randint(1, 99)
#     second = random.randint(1, 99)
#     file.write("(%s)\t%s × %s\n---------------------\n" %(j + 1, first, second))
# file.write("division: \n\n")
# file.write("--------------------------------------------------\n")
# for j in range(division):
#     first = random.randint(1, 9999)
#     second = random.randint(1, 99)
#     file.write("(%s)\t%s ÷ %s\n---------------------\n" %(j + 1, first, second))
# file.write("power2: \n\n")
# file.write("--------------------------------------------------\n")
# for i in range(power2):
#     first = random.randint(1, 99)
#     file.write("(%s)\t%s ^ 2\n---------------------\n" %(i + 1, first))
# file.write("power3: \n")
# file.write("--------------------------------------------------\n")
# for i in range(power3):
#     first = random.randint(1, 999)
#     file.write("(%s)\t%s ^ 3\n---------------------\n" %(i + 1, first))
# file.close()

# n = int(input())
# ps = {}
# divider = 2
# while True:
#     if n == 1:
#         break
#     if n % divider == 0:
#         n = n // divider
#         if ps.get(divider):
#             ps[divider] = ps[divider] + 1
#         else:
#             ps[divider] = 1
#         divider = divider - 1
#     divider = divider + 1
# psl = [(k, v) for k, v in ps.items()]
# numbers = [1, 1, 1]
# for i in range(len(psl)):
#     factor = psl[i][0]
#     alpha = psl[i][1]
#     for j in range(alpha + 1):
#         for k in range(alpha + 1 - j):
#             l = alpha - j - k
#             number[0] = numbers[0] * (factor ** j)
#             number[1] = numbers[1] * (factor ** k)
#             number[2] = numbers[2] * (factor ** l)
            
# print(ps)