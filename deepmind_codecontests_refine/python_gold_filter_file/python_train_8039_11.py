def longpal(s):
    l = len(s)
    ml = 1
    for i in range(1,l):
        s1 = s[:i]
        f = 0
        for j in range(i//2):
            if s1[j]!=s1[i-j-1]:
                f = 1
                break
        if f==0:
            ml = max(ml,i)
    return ml,s[:ml]
# 1
# mmwbbbwmmmgyniywe
cases = int(input())
for t in range(cases):
    s = input()
    l = len(s)
    if l == 1:
        print(s)
    else:
        i = 0
        j = l - 1
        prefix = ''
        while i < j:
            if s[i] == s[j]:
                prefix += s[i]
                i += 1
                j -= 1
            else:
                break
        if i <= j:
            # right palindrome
            l1, s1 = longpal(s[i:j + 1][::-1])
            # left palindrome
            l2, s2 = longpal(s[i:j + 1])
            if l1 >= l2:
                print(prefix + s1 + prefix[::-1])
            else:
                print(prefix + s2 + prefix[::-1])
        else:
            print(prefix + prefix[::-1])

    # print("====")
