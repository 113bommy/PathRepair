b = input()
b = b.split()
ques = int(b[0])
t2t = int(b[1])
count = 240
time = count - t2t
i = 1
while time >= 0:
    time = time - i*5
    i = i + 1
if i-2 >= ques:
    print(ques)
else:
    print(i-2)
