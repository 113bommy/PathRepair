n, f = map(int, input().split())

final = []
for i in range(n):
    products, people = map(int, input().split())
    final.append([products, people])


final.sort(key = lambda x: min(2*x[1],x[0]) - min(x[1], x[0]), reverse = True)


pair = count = 0
while count < f and pair < len(final):
    if final[pair][0] != 0 and final[pair][1] != 0:
        final[pair][0] *= 2
        count += 1
    pair += 1


print(sum(min(i[0], i[1]) for i in final))