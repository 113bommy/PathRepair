n = int(input())
a = list(map(int, input().split()))

man = 0

bank = {25: 0, 50: 0, 100: 0}
f = 0
for i in a:
    if(i == 25):
        bank[25] += 1
    elif(i == 50):
        if(bank[25] >= 1):
            bank[25] -= 1
            bank[50] += 1
        else:
            f = 1
            break
    elif(i == 100):
        if(bank[50] >= 1 and bank[25] >= 1):
            bank[25] -= 1
            bank[50] -= 1
            bank[100] += 1
        if(bank[25] >= 3):
            bank[25] -= 3
            bank[100] += 1
        else:
            f = 1
            break

if(f == 1):
    print("NO")
else:
    print("YES")
