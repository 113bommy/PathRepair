def case1(s:str, n:int):
    val = 0
    count = 0
    for i in range(n):
        if s[i] == '(': val += 1
        else: val -= 1
        if val < 0: return 0
        elif val == 0 or val == 1: count = 0
        elif s[i] == '(': count += 1;
    return count

def case2(s:str, n:int):
    val = 0
    count = 0
    for i in range(n):
        if s[i] == '(': val += 1
        else: val -= 1
        if val == -1:
            val += 2
            for j in range(i+1, n):
                if s[i] == '(': val += 1
                else: val -= 1
                if val < 0: return 0
            return count + 1
        elif s[i] == ')': count += 1
    return count

n = int(input())
s = input()
l = 0
r = 0
for i in range(n):
    if s[i] == '(': l += 1
    else: r += 1
if l - r == 2: print(case1(s, n))
elif l - r == -2: print(case2(s, n))
else: print(0)