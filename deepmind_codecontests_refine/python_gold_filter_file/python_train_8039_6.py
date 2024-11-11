def prefixPalindrome(s):
    n = len(s)
    lst = [0]*n
    i = 1
    l = 0
    while(i < n):
        if s[i] == s[l]:
            l += 1
            lst[i] = l
            i += 1
        else:
            if l != 0:
                l = lst[l-1]
            else:
                lst[i] = 0
                i += 1
    ans = lst[n-1]
    ans = min(n//2, ans)
    return s[:ans]


def longestPorSPalindrome(s):
    s1 = prefixPalindrome(s+'#'+s[::-1])
    s2 = prefixPalindrome(s[::-1]+'#'+s)
    if len(s1)>len(s2):
        return s1
    else:
        return s2    

for _ in range(int(input())):
    s = input()
    n = len(s)
    l = 0
    r = n-1
    while(s[l]==s[r] and l<r):
        l+=1
        r-=1
    if s[l]==s[r]:
        print(s)
        continue
    temp = s[0:l]
    a = s[l:r+1]
    ans = temp+longestPorSPalindrome(a)+temp[::-1]
    print(ans)    