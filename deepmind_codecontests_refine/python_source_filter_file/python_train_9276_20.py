n = int(input())

result_list = list(map(int, input().split()))

for _ in range(1, n):
    l = list(map(int, input().split()))[1:]
    temp = []
    for i in result_list:
        if i in l:
            temp.append(i)

    result_list = temp[:]

print(*set(temp))
