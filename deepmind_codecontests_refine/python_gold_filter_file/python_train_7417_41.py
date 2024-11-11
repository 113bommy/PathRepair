test = int(input())
for t in range(test):
    a = input()
    new = a[1:-1]
    ans = a[0]
    for i in range(0,len(new),2):
        ans += new[i]
    ans += a[-1]
    print(ans)