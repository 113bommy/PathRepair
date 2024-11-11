h1, a1, c1 = map(int, input().split())
h2, a2 = map(int, input().split())

output = []
while h2 > 0:
    if h2==a1:
        output.append("STRIKE")
        h2-=a1
    elif h1>a1:
        output.append("STRIKE")
        h2-=a1
        h1-=a2
    else:
        output.append("HEAL")
        h1+=c1
        h1-=a2

print(len(output))
for i in range(len(output)):
    print(output[i])
