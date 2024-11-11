h = [[0 in range(10)] for j in range(10)]
for i in range(1, 4):
    h[i] = [0 for j in range(i + 1)] + list(map(int, input().split()))
#for i in range(1, 4):
#    print(" ".join(map(str, h[i][1:5])))
if (h[1][2] + h[1][3] < h[2][3] or (h[1][2] + h[1][3] - h[2][3]) % 2 == 1):
    print("-1")
    exit(0)

BB = (h[1][2] + h[1][3] - h[2][3]) // 2
BA = h[1][2] - BB
AB = h[1][3] - BB
NowB = h[1][4]
NowLen = BB + AB + BA
Now24 = BA + NowB + BB
Now34 = AB + NowB + BB
BAB = 0
ABB = 0
BBB = 0

Dif = (BA - AB) - (h[2][4] - h[3][4])
if (abs(Dif) % 2 == 1):
    print("-1")
    exit(0)
if Dif < 0:
    ABB += abs(Dif) // 2
    Now34 -= ABB * 2
    #Now24 += ABB
    if (AB < ABB or NowB < ABB):
        print("-1")
        exit(0)
    NowB -= ABB
else:
    BAB += Dif // 2
    Now24 -= BAB * 2
    #Now34 += BAB
    if (BA < BAB or NowB < BAB):
        print("-1")
        exit(0)
    NowB -= BAB
if (Now24 < h[2][4] or (Now24 - h[2][4]) % 2 == 1):
    print("-1")
    exit(0)
#print(Now34 - h[3][4])
for i in range(BB + 1):
    if (i > NowB):
        break
    Now = i * 2
    if (Now > Now24 - h[2][4]):
        break
    if min([(NowB - i) // 2, BA - BAB, AB - ABB]) * 2 >= Now24 - h[2][4] - Now:
        #print(i, Now24, h[2][4], NowB)
        BBB += i
        BAB += (Now24 - h[2][4] - Now) // 2
        ABB += (Now24 - h[2][4] - Now) // 2
        NowB -= i + (Now24 - h[2][4] - Now)
        print(NowLen + NowB)
        print("".join(["a" for j in range(NowLen)] + ["a" for j in range(NowB)]))
        print("".join(["a" for j in range(AB)] + ["b" for j in range(BB + BA)] + ["a" for j in range(NowB)]))
        print("".join(["b" for j in range(AB + BB)] + ["a" for j in range(BA)] + ["a" for j in range(NowB)]))
        print("".join(["b" for j in range(ABB)] + ["a" for j in range(AB - ABB)] + ["b" for j in range(BBB)] + ["a" for j in range(BB - BBB)] + ["b" for j in range(BAB)] + ["a" for j in range(BA - BAB)] + ["b" for j in range(NowB)]))
        exit(0)
print("-1")
