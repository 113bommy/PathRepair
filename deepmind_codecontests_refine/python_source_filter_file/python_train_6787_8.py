P = 10 ** 9 + 7
n, m = tuple([int(x) for x in input().split()])

mx = max(n, m)
vals = [0] * mx
for i in range(mx):
    if i == 0 or i == 1:
        vals.append(i)
    
    else:
        new_val = (vals[-1] + vals[-2]) % P
        vals.append(new_val)


x = (vals[n-1] + vals[m-1]) % P
x = (x - 1) % P
x = (x * 2) % P

print(x)