def main():
    s = input()
    flag = False
    st = -1
    fn = -1
    for i in range(27):
        for j in range(i + 2, 27):
            if (s[i] == s[j]):
                flag = True
                st = i
                fn = j
                break
    if (not flag):
        print("Imossible")
        return
    
    s = s[st:] + s[:st]
    add = st
    fn -= st
    st = 0
    
    ans = [["%"] * 13 for i in range(2)]
    sx = -1
    sy = 1
    if (fn % 2 == 0):
        st_ind = (fn // 2 - 1)
        for i in range(st_ind + 1):
            ans[0][st_ind - i] = s[i]
        for i in range(st_ind + 1):
            ans[1][i] = s[st_ind + 1 + i]

        sx = st_ind + 1
    else:
        st_ind = (fn // 2)
        for i in range(st_ind + 1):
            ans[0][st_ind - i] = s[i]
        for i in range(st_ind):
            ans[1][i] = s[st_ind + 1 + i]    
        sx = st_ind
    for i in s[fn + 1:]:
        ans[sy][sx] = i
        if (sy == 1):
            if (sx == 12):
                sy -= 1
            else:
                sx += 1
        else:
            sx -= 1
    print("".join(ans[0]))
    print("".join(ans[1]))
main()
