n = int(input())
start = input()
kod = input()
a = '0123456789'
b = '567890123'
qty = 0
for i in range(n):
    if start[i] >= kod[i] and int(start[i]) - int(kod[i]) <= 4:
        qty = qty + int(start[i]) - int(kod[i])
    elif start[i] <= kod[i] and int(kod[i]) - int(start[i]) <= 4:
        qty = qty + int(kod[i]) - int(start[i])
    else:
        if start[i] > kod[i]:
            qty = qty - b.find(start[i]) + b.find(kod[i])
        else:
            qty = qty + b.find(start[i]) - b.find(kod[i])
print(qty)



