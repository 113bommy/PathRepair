tc = int(input())
for i in range(tc):
    n = int(input())
    ip = input()
    if (len(ip) == 2 and int(ip[0]) > int(ip[1])):
        print("NO")
    else:
        print("YES")
        n = 2
        print(n)
        print(ip[0], ip[1:])