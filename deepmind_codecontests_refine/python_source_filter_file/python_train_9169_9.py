# import os


t = int(input())

a = list(map(int, input().split()))

r = 0
for item in list(set(a)):
    new = a.count(item)
    if new > r:
        r = new
print(new)
    


    

# 03/01 - 1
# 04/01 - 21
# 05/01 - 27
# 06/01 - 4

