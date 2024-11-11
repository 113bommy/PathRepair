emp = int(input())
opt = 0
for i in range(1,emp):
    if i == 1:
        opt += 1
        continue
    bosses = i
    employees = emp - i
    if bosses <= employees and employees % bosses == 0:
        opt += 1
print(opt)
