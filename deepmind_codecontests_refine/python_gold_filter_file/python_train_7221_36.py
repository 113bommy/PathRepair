x = []
for l in range(5):
    x.append(input().split())
y = ""
for i in range(len(x)):
    if x[i].count("1") == 1:
        y = i
print(abs(2- y)+abs( 2- x[y].index("1")))