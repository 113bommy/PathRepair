x=[int(input()) for i in range(4)]
if x[1] <= x[2] - x[3] or x[0] < x[2]:
    print(x[0]//x[1])

else:
    maxx = (x[0] - x[2]) // (x[2] - x[3])
    ans = -1
    for i in range(max(0, maxx-1000), maxx+5):
        if ((x[2] - x[3]) * (i-1) + x[2] > x[0]):
            continue
        ans = max(ans, i + (x[0] - (i * (x[2] - x[3]))) // x[0])
    print(ans)
