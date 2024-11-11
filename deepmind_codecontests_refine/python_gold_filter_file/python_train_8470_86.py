n=int(input())
for i in range(n+1,90000):
    if len(set(str(i)))==4:
        print(i)
        break
