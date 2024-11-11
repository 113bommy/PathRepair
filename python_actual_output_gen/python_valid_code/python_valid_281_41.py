n, m = map(int, input().split())
s = input().split()
t = input().split()

q = int(input())
for i in range(0, q):
        y = int(input())
        sd = s[(y % n)]
        td = t[(y % m)]
        print(sd+td)

