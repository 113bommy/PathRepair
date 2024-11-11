from sys import stdin
a = int(stdin.readline().rstrip())
for _ in range(a):
    n, m = map(int, stdin.readline().rstrip().split(" "))
    r = "YES"
    for i in range(n):
        l = list(map(int, stdin.readline().rstrip().split(" ")))
        for j in range(m):
            if i == 0 or i == n-1:
                if j ==0 or j == m- 1:
                    if l[j]>1:
                        r = "NO"
                else:
                    if l[j]>3:
                        r = "NO"
            else:
                if j ==0 or j == m- 1:
                    if l[j]>2:
                        r = "NO"
                else:
                    if l[j]>4:
                        r = "NO"
    if r =="YES":
        print("YES")
        for i in range(n):
            if i == 0 or i == n-1:
                print("2", "3 "*(m-2), end ="")
                print("2")
            else:
                print("3", "4 "*(m-2), end="")
                print("3")
    else:
        print("NO")