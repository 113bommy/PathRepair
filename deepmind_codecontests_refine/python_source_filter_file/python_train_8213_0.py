ans_list = []
n = int(input())

def mcxl2digit(s):
    ans = 0
    dig = 1
    for i in range(len(s)):
        if "2" <= s[i] <= "9":
            dig = int(s[i])
        else:
            if s[i] == "m":
                key = 1000
            elif s[i] == "c":
                key = 100
            elif s[i] == "x":
                key = 10
            else:
                key = 1
            ans += key * dig
            dig = 1
    return ans

def digit2mcxl(i):
    return_list = []
    m = i // 1000
    if m != 0 and m != 1:
        return_list.append(str(m))
    if m != 0:
        return_list.append("m")
    i = i % 1000

    c = i // 100
    if c != 0 and c != 1:
        return_list.append(str(c))
    if c != 0:
        return_list.append("c")
    i = i % 100

    x = i // 10
    if x != 0 and x != 1:
        return_list.append(str(x))
    if x != 0:
        return_list.append("x")
    i = i % 10

    l = i
    if l != 0 and l != 1:
        return_list.append(str(l))
    if l != 0:
        return_list.append("l")

    return return_list

for i in range(n):
    a, b = input().split()
    ans = (mcxl2digit(a) + mcxl2digit(b))
    #print(a, b, mcxl2digit(a), mcxl2digit(b))
    #print(ans)
    ans = digit2mcxl(ans)
    ans_list.append(ans)
for i in ans_list:
    print("".join(i))
