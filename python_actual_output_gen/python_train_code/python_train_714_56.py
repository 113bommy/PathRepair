a, v = map(int,input().split())
b, w = map(int,input().split())
t = int(input())


if (v-w>0 & abs(a-b) <= t*(v-w)):
    print("YES")
else:
    print("NO")