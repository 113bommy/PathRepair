q = int(input())

for i in range(q):
    n = int(input())
    str = input()

    fn = str[0];
    sn = str[1:];

    if int(fn) == int(sn):
        print("NO")
    else:
        print("YES")
        print(2)
        print("{} {}".format(fn, sn));