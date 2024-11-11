s = input()

c1 = s.count('4')
c2 = s.count('7')
if c1 == 0 or c2 == 0: print(-1)
else: 
    if c1 >= c2: print(4)
    else: print(7)