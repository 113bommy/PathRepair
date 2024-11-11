n = int(input())
for i in range(n + 1, 9100):
    temp = i
    s = set()
    while(temp):
        s.add(temp % 10)
        temp //= 10
    if(len(s) == 4):
        print(i)
        break