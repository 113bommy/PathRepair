import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

e = [0] * (N+1)

for i in range(2, N+1):
    cur = i
    for j in range(2, i+1):
        while cur % j == 0:
            e[j] += 1
            cur //= j

def num(n):
    return len(list(filter(lambda x: x >= n-1, e)))

# num(3)-1はnum(25)で3以上のものを一個使っているので、一つ引いている。//2は、例えばa^4 * b^4 * c^2 と b^4 * a^4 * c^2がかぶって計上されるため。
print(num(75) + num(25)*(num(3)-1) + num(15)*(num(5)-1) + num(5)*(num(5)-1)*(num(3)-2)//2)