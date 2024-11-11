case = int(input())
for x in range(case):
    y,z = map(int,input().split())
    print("{first} {second}".format(first=x, second =x+x))
