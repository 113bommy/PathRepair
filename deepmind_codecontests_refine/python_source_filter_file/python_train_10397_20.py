n, k = map(int, input().split())
d = map(str, input().split())
digits = set(d)
num = {str(i) for i in range(0,10)}
left = num - digits
for i in range(N, 100000):
    Num = set(str(i))
    if Num <= left:
        print(i)
        break