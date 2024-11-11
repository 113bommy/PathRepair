a = int(input())
b = list(map(int,input().split()))
b.sort
if b[1] - b[0] > b[-1] - b[-2]:
    print(b[-1] - b[1])
elif b[1] - b[0] < b[-1] - b[-2]:
    print(b[-2] - b[0])
else:
    print(b[-1] - b[1])