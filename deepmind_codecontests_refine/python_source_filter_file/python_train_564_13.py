def check(a, b):
    for i in a:
        if i not in b:
            return False
        else:
            if a[i] > b[i]:
                return False
    return True


def c(s, t):
    for i in range(len(s)):
        if s[i] != t[i]:
            return False
    return True


def lcs(X, Y):
    m = len(X)
    n = len(Y)

    L = [[None]*(n + 1) for i in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1]+1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    return L[m][n]


s = input()
t = input()
dic1 = {}
dic2 = {}
for i in s:
    dic1[i] = dic1.get(i, 0)+1
for i in t:
    dic2[i] = dic2.get(i, 0)+1

if len(s) == len(t):
    # swap
    if check(dic1, dic2):
        print("array")
    else:
        print("need tree")

elif len(s) < len(t):
    print("need tree")
else:
    # remove
    if check(dic2, dic1):

        if lcs(s, t) == len(t):
            print("array")
        else:
            print("both")

    else:
        print("need tree")
