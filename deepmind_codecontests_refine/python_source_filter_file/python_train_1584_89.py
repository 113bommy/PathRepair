n = int(input())

l = {1:0, 2:0}

def is_composite(x):
    if x in l:
        return l[x]
    for j in range(2, int(x ** 0.5 + 1)):
        if x % j == 0:
            l[x] = 1
            return True
    l[x] = 0
    return False

ans_a = ans_b = 0
for i in range(10000000):
    j = i+n
    if is_composite(i) and is_composite(j):
        ans_a = i
        ans_b = j
        break

print(ans_a, ans_b)    

