from sys import stdin
input = stdin.readline

n = int(input())
s = input()

num_res = 0
s_res = ['']*n

i = 0
while i < (n-1):
    if s[i] != s[i+1]:
        s_res[i-num_res] = s[i]
        s_res[i+1-num_res] = s[i+1]
        i += 2
    else:
        s_act = s[i]
        i += 1
        while i < n and s_act == s[i]:
            i += 1
            num_res += 1
        if i != n:
            s_res[i-num_res], s_res[i-num_res+1] = s_act, s[i]
            i += 1
        else: num_res += 1

if i == (n-1): num_res += 1
        
print(num_res)
print(''.join(s_res))
