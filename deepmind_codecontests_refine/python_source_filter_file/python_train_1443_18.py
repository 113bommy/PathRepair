n = int(input())
a_list = list(map(int, input().split()))
zero = a_list.count(0)
D = 1000000000 + 7
a_set = set(a_list)
if zero == 1 and n -1 == 2 * len(a_set):
    print(2 ** ((n-1)//2) % D)
elif zero == 0 and n == 2 * len(a_set):
    print(2 ** (n//2) % D)
else:
    print(0)