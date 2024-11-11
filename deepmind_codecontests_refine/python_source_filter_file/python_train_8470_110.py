from collections import Counter
n=int(input())
for i in range(n+1,9000):
    j=str(i)
    freq=Counter(j)
    if len(freq)==len(j):
        print(int(j))
        break