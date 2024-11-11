s = list(input())
x, y = map(int, input().split())

z = [0]
for i in s:
    if i=='F':
        z[-1] += 1
    else:
        z.append(0)
_y = len(z)//2
_x = len(z) - _y
len_s = len(s)
dp_x = [0 for _i in range((2*len_s+2))]
dp_x_to = [0 for _i in range((2*len_s+2))]
dp_y = [0 for _i in range((2*len_s+2))]
dp_y_to = [0 for _i in range((2*len_s+2))]

dp_x[z[0]] = 1
dp_y[0] = 1

for i in range(1, len(z)):
    if i%2==0:
        for j in range(-len_s, len_s+1):
            dp_x_to[j] = max(
                dp_x[j-z[i]],
                dp_x[j+z[i]]
            )
        dp_x = dp_x_to.copy()
    else:
        for j in range(-len_s, len_s+1):
            dp_y_to[j] = max(
                dp_y[j-z[i]],
                dp_y[j+z[i]]
            )
        dp_y = dp_y_to.copy()

if dp_x[x] == dp_y[y] == 1:
    print('Yes')
else:
    print('No')