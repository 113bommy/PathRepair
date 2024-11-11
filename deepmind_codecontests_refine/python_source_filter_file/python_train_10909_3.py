N = int(input())
S = input()

c = 0
for i in range(1000):
    num_str = "{0:0>3}".format(i)
    j = 0
    for s in S:
        if num_str[j] == s:
            j += 1
        if j == 3:
            c += 1
            break

print(c)