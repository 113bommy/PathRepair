prices = int(input())
x = input().split(" ")
x = list(x)

me = 1
friend = 1000000
timer = 0
i = 0
j = len(x)-1
while me <= 500000 and friend >= 500000:
    if me == int(x[i]):
        prices = prices - 1
        i = i+1
    if friend == int(x[j]):
        prices = prices - 1
        j = j-1
    me = me + 1
    friend = friend - 1
    if prices == 0:
        print(timer)
        break
    timer = timer + 1





