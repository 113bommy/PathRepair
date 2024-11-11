from sys import stdin, stdout

lst = list(map(int, stdin.readline().strip().split()))
rem = lst[0] % lst[1]
if rem == 0:
    stdout.write('0')
else:
    cons_cost = (lst[1] - rem) * lst[2]
    dest_cost = rem * lst[3]
    stdout.write(str(max(cons_cost, dest_cost)))