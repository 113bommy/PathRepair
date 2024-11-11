def f(x):
        if x == n:
                return "0"
        if x == 0:
                return "(" + str(X[0]) + "+" + f(1) + ")"
        ss = "(abs(t-" + str(x-1) + ")-abs(t-" + str(x)  + "))"
        tmp = (X[x] - X[x - 1]) // 2
        re = (X[x] - X[x - 1]) -  2 * tmp
        X[x] -= re
        if tmp < 0:
                tmp = "(0" +str(tmp)+")"
        ss = "((" + str(tmp) + "*" + ss + ")" + "+" + str(tmp) + ")"
        return "(" + ss + "+" + f(x + 1) + ")"

n = int(input())
#c = [(int(_) for _ in input().split()) for i in range(n)]
c = [[int(x) for x in input().split()] for i in range(n)]
#print(n, c)
X = [c[i][0] for i in range(n)]
Y = [c[i][1] for i in range(n)]
#print(X)
#print(Y)
print(f(0))
#print(X)
X = Y
print(f(0))
