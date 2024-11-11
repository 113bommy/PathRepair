from sys import stdin as fin
# fin = open("cfr417a.in", "r")

# n = int(fin.readline())
arr = [list(map(int, fin.readline().split())) for i in range(4)]
for i in range(4):
    if (arr[i][0] or arr[i][1] or arr[i][2] or arr[i-1][2] or arr[i-2][1] or arr[i-3][0]) and arr[3]:
        print("YES")
        break
else:
    print("NO")