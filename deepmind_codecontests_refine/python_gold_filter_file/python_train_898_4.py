n = int(input())
a = list()
for i in range(n):
    b = input().split()[1]
    a.append(b == 'soft' if 1 else 0)
    
white = a.count(1)
black = a.count(0)

for sz in range(1, 100):
    bl = 0
    wh = 0
    bl2 = 0
    wh2 = 0
    
    if sz % 2 == 0:
        wh = sz*sz // 2
        bl = sz*sz // 2
        wh2 = wh
        bl2 = bl
    else:
        wh = sz*sz // 2 + 1
        bl = sz*sz // 2
        wh2 = sz*sz // 2
        bl2 = sz*sz // 2 + 1
        
    if ((white <= wh) and (black <= bl)) or ((white <= wh2) and (black <= bl2)):
        print(sz)
        exit()