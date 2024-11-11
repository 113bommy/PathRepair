n = int(input())
a = list(map(int, input().split()))
a_set = set(a)
if len(a) % 2 == 0:
    print(len(a_set) - 1)
else:
    print(len(a_set))
