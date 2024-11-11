N = int(input())
X = input()
popcount_X = X.count('1')
numX = int(X, 2)
a = numX % (popcount_X + 1)
b = numX % (popcount_X - 1) if popcount_X != 1 else 0
for i, x in enumerate(X, 1): #リストのインデクス，要素，第二引数に開始位置
    if x == '1' and popcount_X == 1:
        print(0)
        continue
    ans = 1
    if x == '1':
        temp = (b - pow(2, N - 1, popcount_X - 1)) % (popcount_X - 1)
    else:
        temp = (a + pow(2, N - i, popcount_X + 1)) % (popcount_X + 1)
    while temp:
        p = format(temp, 'b').count('1') #2進数，1の個数
        temp %= p
        ans += 1
    print(ans)