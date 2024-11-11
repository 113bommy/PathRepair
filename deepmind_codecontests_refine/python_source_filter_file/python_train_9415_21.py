n,d = [int(i) for i in input().split()]
line = [int(i) for i in input().split()]
num = len(line)
time = sum(line)+10*(num-1)
if time >= d:
    print('-1')
else:
    print(2*(num-1)+(d - time)//5)