ins = input().split()
num = int(ins[0])
if ins[2] == "week":
    print(53 if num in range(5, 8) else 52)
else:
    print(12 if num <30 else 11 if num < 31 else 7)
