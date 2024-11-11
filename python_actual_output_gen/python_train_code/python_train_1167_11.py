n,m = map(int,input().split())
I = True
X = ''
for i in range(n):
    X += input()
    if ("C" in X)or("M" in X)or("Y" in X):
        I = False
else:
    if I:
        print("#Black*White")
    else:
        print("#Color")