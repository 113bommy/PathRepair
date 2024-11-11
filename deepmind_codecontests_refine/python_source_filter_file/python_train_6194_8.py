def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


from sys import stdin

n, a = int(input()), sorted(arr_inp(1))
print(-1 if a[0] == 1 else a[0] - 1)
