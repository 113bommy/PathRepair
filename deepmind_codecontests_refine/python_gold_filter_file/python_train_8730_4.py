lst=[0 for i in range(51)]
for a in range(10):
    for b in range(10):
        for c in range(10):
            for d in range(10):
                lst[a+b+c+d] += 1
while 1:
    try:
        print(lst[int(input())])
    except:
        break
