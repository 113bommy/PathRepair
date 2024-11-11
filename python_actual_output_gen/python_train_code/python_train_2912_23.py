n = int(input())
while n < 9000:
    n+=1
    if len(set(str(n))) >= 4:
        print(n)
        break
