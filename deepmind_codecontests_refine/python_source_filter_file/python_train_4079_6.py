def intersection(X,curr,x):
    if curr == 'a':
        if X[0] > x:
            return []
        X[1] = min(X[1],x)
    else:
        if X[1] > x:
            return []
        X[0] = min(X[0],x)

    return X

def solve(n,ans):
    found = True
    X = [-10**5,10**5]
    Y = [-10**5,10**5]

    for i in range(n):
        x,y,a,b,c,d = map(int,input().split())
        if found:
            if a+c == 1:
                if a == 1:
                    if not intersection(X,'a',x):
                        found = False
                else:
                    if not intersection(X,'c',x):
                        found = False
            elif a+c == 0:
                if X[0] <= x and X[1] >= x:
                    X = [x,x]
                else:
                    found = False
                    

            if b+d == 1:
                if d == 1:
                    if not intersection(Y,'a',y):
                        found = False
                else:
                    if not intersection(Y,'c',y):
                        found = False
            elif b+d == 0:
                if Y[0] <= y and Y[1] >= y:
                    Y = [y,y]
                else:
                    found = False

    #print(X,Y)
    if not found:
        ans.append(0)
    else:
        ans.append('1 '+str(X[0])+' '+str(Y[0]))
                

def main():
    ans = []
    q = int(input())
    for i in range(q):
        n = int(input())
        solve(n,ans)

    for i in ans:
        print(i)

main()
