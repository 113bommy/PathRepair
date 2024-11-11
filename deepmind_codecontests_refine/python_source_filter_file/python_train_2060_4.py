


n = list(map(int, list(input())))[::-1] + [0]
sum1 = sum(n)
for i in range(len(n)-1):
    if n[i] > 5 or (n[i]==5 and n[i+1]==5):
        n[i] = 10-n[i]
        n[i+1] += 1
print(min(sum1, sum(n)))
