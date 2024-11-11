

n = int(input())

min_1, max_1 = map(int, input().split())
min_2, max_2 = map(int, input().split())
min_3, max_3 = map(int, input().split())

a_1 = min(max_3, n - min_1 - min_2)

a_2 = min(max_2, n - a_1 - min_1)

a_3 = n - a_1 - a_2

print(str(a_3) + " " + str(a_2) + " " + str(a_1))


