N = int(input())

a_list = map(int, input().split())
a_list = sorted(a_list)

print(sum(a_list[N:2 * N]))