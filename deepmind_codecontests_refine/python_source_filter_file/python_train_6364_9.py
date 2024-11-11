t = 100001
naj = 0
n = int(input())
a = [int(x) for x in input().split()]
for i in range(101):
    temp = 0
    for x in a:
        temp += (abs(i - x) - 1,0)[abs(i - x) == 0]
    if temp < t:
        t = temp
        naj = i
print(naj,t)