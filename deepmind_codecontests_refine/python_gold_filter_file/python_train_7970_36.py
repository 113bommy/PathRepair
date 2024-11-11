n, k = map(int, input().split())
total = 0
for i in range(1, n+1):
    total += 5*i
    # print(total, i)
    if total + k > 240:
        print(i-1)
        break
    # elif x-total > 0:
    #     print(i)
    #     break
else:
    print(n)