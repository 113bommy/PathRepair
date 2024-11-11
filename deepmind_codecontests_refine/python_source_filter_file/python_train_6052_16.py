hori = 1
veri = 1
for i in input():
    if i == '1':
       print(hori,2)
       hori += 2
       if hori > 4:
           hori = 1
    else:
        print(veri,1)
        veri += 2
        if veri > 4:
            veri = 1