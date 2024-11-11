def b():
    n = int(input())
    d = []
    r = []
    count = 0.0
    d = input().split(" ")
    r = input().split(" ")
    for i in range(100000):
        for j in range(n):
            if((i % int(d[j])) == int(r[j])):
                count += 0.00001
                break

    print(round(count,6))

b()



