for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    num = []
    for i in range(n):
        x = bin(l[i])[2:]
        num.append(x)
    count = 0
    num1 = [0]*100000
    for i in range(n):num1[len(bin(l[i]))] += 1
    for i in num1:
        count += i*(i-1)//2
print(count)