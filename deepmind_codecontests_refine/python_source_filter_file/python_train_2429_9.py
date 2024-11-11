import sys
input = lambda: sys.stdin.readline().strip("\r\n")

n = int(input())
a = list(int(x) for x in input())
start = sorted(a[:len(a)//2])
end = sorted(a[len(a)//2:])
if start[0] < end[0]:
    for i in range(len(a)//2):
        if end[i] < start[i]:
            print("NO")
            break
    else:
        print("YES")
elif start[0] > end[0]:
    for i in range(len(a)//2):
        if end[i] > start[i]:
            print("NO")
            break
    else:
        print("YES")
else:
    print("NO")
