def f(s1, s2):
    result = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            result += 1
    if result % 2 == 1:
        return 'impossible'
    s, answer = '', result // 2
    for i in range(len(s)):
        if s1[i] == s2[i]:
            s += s[i]
        else:
            if answer > 0:
                s += s[i]
                answer -= 1
            else:
                answer += s2[i]
    return s


t1 = input()
t2 = input()
print(f(t1, t2))
