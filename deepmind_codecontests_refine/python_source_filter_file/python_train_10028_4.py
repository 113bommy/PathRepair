results = []
data = []
for i in range(int(input())):
    data.append(int(input()))
for a in data:
    if a == 1:
        results.append(1)
    else:
        res = [1]
        sum = 1
        i = 1
        k = 2
        while sum + i + k <= a:
            new_number = i + k
            res.append(new_number)
            sum += new_number
            i = new_number
        res.append(a - sum)
        results.append(len(res))

for i in results:
    print(i)