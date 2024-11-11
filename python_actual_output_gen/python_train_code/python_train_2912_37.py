year = int(input())
for i in range(year+1,9000):
    if len(set(str(i)))==4:
        print(i)
        break