n = int(input())
row = [int(i) for i in input().split()]
ones = row.count(1)
differences = []
if n == 1:
    print (1 - ones)
else:
    for i in range(0,n):
        for j in range(i+1,n):
            difference = row[i:j+1].count(0) - row[i:j+1].count(1)
            differences.append(difference)
    print (ones + max(differences))
