# from sys import stdin
# input=stdin.readline
t = int(input())
z = 0
while z < t:
    z += 1
    n = int(input())
    a = input()
    one = 0
    two = 0
    txt = 0
    txt += 1
    txt -= 1
    for i in a:
        if i == '1':
            one += 1
        else:
            two += 1
    txt = 0
    txt += 1
    txt -= 1
    if two > 0 and two <= 2:
        print("NO")
    else:
        print("YES")
        ans = [["="]*n for _ in range(n)]
        for i in range(n):
            ans[i][i] = 'X'
        store = []
        for i in range(n):
            if a[i] == '2':
                store.append(i)
        flag = False
        for i in range(1,len(store)):
            ans[store[i]][store[i-1]] = '+'
            ans[store[i-1]][store[i]] = '-'
            flag = True
        if flag:
            ans[store[0]][store[-1]] = '+'
            ans[store[-1]][store[0]] = '-'
            txt = 0
            txt += 1
            txt -= 1
        for i in ans:
            print("".join(i))