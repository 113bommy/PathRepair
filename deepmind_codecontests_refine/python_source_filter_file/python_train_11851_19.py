import math
k = int(input())
if k == 3:
    print("3 6 9")
elif k == 4:
    print("3 9 2 4")
elif k == 6:
    print("3 9 2 4 8 10")
elif k <= 15002:
    prints = set([3, 9]) 
    k -= 2
    for i in range(int(math.ceil(k / 3))):
        prints.add(i*6+2)
        prints.add(i*6+4)
        prints.add(i*6+6)
    if 3 - k % 3 == 1:
        prints.remove(6)
    if 3 - k % 3 == 2:
        prints.remove(6)
        prints.remove(12)
    print(" ".join([str(item) for item in prints]))
else:
    prints = set() 
    for i in range(5000):
        prints.add(i*6+2)
        prints.add(i*6+4)
        prints.add(i*6+6)
    k -= 15000
    for i in range(int(math.ceil(k / 2))):
        prints.add(i*12+3)
        prints.add(i*12+9)
    if 3 - k % 3 == 1:
        prints.remove(6)
    print(" ".join([str(item) for item in prints]))