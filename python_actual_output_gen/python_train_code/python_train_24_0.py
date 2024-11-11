n, k = map(int, input().split())
str_input = input()
num = [int(i) for i in str_input.split()]
can_be = []
for m in num:
    if k%m == 0:
        can_be.append(m)
the_result = sorted(can_be)
print(the_result[0])