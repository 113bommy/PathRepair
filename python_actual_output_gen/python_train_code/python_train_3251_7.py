n = int(input())
data = list(map(int,input().split()))

data.sort()

def check(ind):
    return data[ind] + data[ind  +1 ] >= data[ind  +2]

for  i in range(n - 2):
    if check(i):
        print("YES")
        exit(0)

print("NO")
