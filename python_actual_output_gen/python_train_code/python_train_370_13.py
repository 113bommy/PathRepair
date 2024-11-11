x, y, z = [int(i) for i in input().split()]

totalCoco = (x+y)//z
sashaCoco = x//z
mashaCoco = y//z
if sashaCoco + mashaCoco == totalCoco:
    print(totalCoco, 0)
else:
    print(totalCoco, min(x % z, y % z))