a = int(input())
for i in range(a+1,9999):
    if len(set(str(i))) == 4:
        print(i)
        break
