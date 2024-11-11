n = int(input())

T = [False for i in range(10)]
s = input()

for i in s:
    T[int(i)] = True

if ((T[1] or T[2] or T[3]) and (T[7] or T[8] or T[9]) and (T[1] or T[4] or T[7]) and (T[3] or T[6] or T[9])) \
    or (T[0] and (T[1] or T[2] or T[3])):
    print("YES")
else:
    print("NO")
