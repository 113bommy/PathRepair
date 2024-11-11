### A. Distinct Digits
l,r = map(int, input().split())
for i in range(l,r):
    i=str(i)
    if len(set(i)) == len(i):
        print(i)
        break
else:
    print(-1)