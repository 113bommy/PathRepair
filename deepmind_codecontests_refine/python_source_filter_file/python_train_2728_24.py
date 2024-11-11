from sys import stdin
for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    a = [int(x) for x in stdin.readline().split()]
    for i in range(1,n-1):
        if abs(a[i-1]-a[i]) >= 2:
            print("YES")
            print(i,i+1)
            break
    else:
        print("NO")