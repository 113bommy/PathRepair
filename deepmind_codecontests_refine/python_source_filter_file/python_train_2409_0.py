n = int(input())
s = input()
s = s.split()
s1 = []
max = 0
ans = 1
max_len = 1
for i in range(n):
    s1.append(int(s[i]))
for k in s1:
    if k > max:
        max = k
if len(s1) == 1:
    max_len = 1
for i in range(n):
    if s1[i] == max:
        if i != n - 1 and s1[i+1] == max:
            ans += 1
        else:
            if ans > max_len:
                max_len = ans
                ans = 1
print(max_len)


