n = int(input())

for i in range(n+1, 8977):
    if len(set(str(i))) == 4:
        print(i)
        break
