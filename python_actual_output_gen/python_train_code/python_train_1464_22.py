a=int(input())
count = 0
base = 5
while a > 0:
    if a % base == 1:
        count+=1
    a = a // base
print(count)