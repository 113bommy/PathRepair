n = int(input())
for i in range(n):
    s = int(input())
    print("Case {}:".format(i+1))
    for _ in range(10):
        s = int("{:08d}".format(s ** 2)[2:7])
        print(s)