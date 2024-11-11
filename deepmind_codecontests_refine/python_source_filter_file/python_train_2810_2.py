while True:
    po = input()
    if po == '#':
        break
    y,m,d = [int(i) for i in po.split()[1:]]
    if y > 32 or (y == 31 and m > 4):
        print(f"? {y-30} {m} {d}")
    else:
        print(f"HEISEI {y} {m} {d}")
        

