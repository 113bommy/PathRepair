a  = int(input())
mas = input()
count1 = 0
count2 = 0
count3 = 0
count4 = 0
for i in range(0, (a), 2):  #rbrb
    if (mas[i] == 'b'):
        count1 += 1
for i in range(1, (a), 2):
    if (mas[i] == 'r'):
        count2 += 1
for i in range(1, (a), 2):  #brbr
    if (mas[i] == 'r'):
        count3 += 1
for i in range(0, (a), 2):
    if (mas[i] == 'b'):
        count4 += 1


# print(count1)
# print(count2)
# print(count3)
# print(count4)
print(min(max(count2,count1),max(count4,count3)))