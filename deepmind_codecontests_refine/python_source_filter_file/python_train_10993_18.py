n = int(input())
k = 1
max = 0


while True:
    max = max + 2**k * 5
    min = max - (2**k * 5)
    if min <= n <= max:
        break
    k += 1
        

if (n - min) % 2**k == 0:
    who = (n - min) // 2**k
elif (n - min) % 2**k != 0:
    who = ((n - min) // 2**k) + 1
    
if who == 1:
    print("Sheldon")
elif who == 2:
    print("Leonard")
elif who == 3:
    print("Penny")
elif who == 4:
    print("Rajesh")
elif who == 5:
    print("Howard" )
    
