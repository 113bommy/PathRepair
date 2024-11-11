n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort()
if a[-m] > sum(a)*1/(4*m):
    print("Yes")
else:
    print("No")