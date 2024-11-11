positions = {"v": 0, "<": 1, "^": 2, ">": 3}
q = input().split()
n = int(input())
start = positions.get(q[0])
finish = positions.get(q[1])

if n % 2 == 0:
    print("undefind")
elif (start+n) % 4 == finish:
    print("cw")
else:
    print("ccw")