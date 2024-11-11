def permutate(s):
    answer = 1000
    n = len(s)
    z = 0
    if s.count('2') >= 1 and s.count('5') >= 1:
        k1 = s.rfind('2')
        k2 = s.rfind('5')
        s1 = s[:k1] + s[(k1 + 1):]
        m = s1.rfind('5')
        s2 = s1[:m] + s1[(m + 1):]
        if len(s2) > 0 and s2[0] == '0':
            for i in range(1, len(s2)):
                if s2[i] != '0':
                    z = i
                    break
        if k2 < k1:
            answer = min(answer, 2 * n - k2 - k1 - 2 + z)
        elif k2 > k1:
            answer = min(answer, 2 * n - k2 - k1 - 3 + z)
    z = 0
    if s.count('5') >= 1 and s.count('0') >= 1:
        k3 = s.rfind('5')
        k4 = s.rfind('0')
        s1 = s[:k3] + s[(k3 + 1):]
        m = s1.rfind('0')
        s2 = s1[:m] + s1[(m + 1):]
        if len(s2) > 0 and s2[0] == '0':
            for i in range(1, len(s2)):
                if s2[i] != '0':
                    z = i
                    break
        if k4 < k3:
            answer = min(answer, 2 * n - k4 - k3 - 2 + z)
        elif k4 > k3:
            answer = min(answer, 2 * n - k4 - k3 - 3 + z)
    z = 0
    if s.count('7') >= 1 and s.count('5') >= 1:
        k5 = s.rfind('7')
        k6 = s.rfind('5')
        s1 = s[:k5] + s[(k5 + 1):]
        m = s1.rfind('5')
        s2 = s1[:m] + s1[(m + 1):]
        if len(s2) > 0 and s2[0] == '0':
            for i in range(1, len(s2)):
                if s2[i] != '0':
                    z = i
                    break
        if k6 < k5:
            answer = min(answer, 2 * n - k5 - k6 - 2 + z)
        elif k6 > k5:
            answer = min(answer, 2 * n - k6 - k5 - 3 + z)
    z = 0
    if s.count('0') > 1:
        k7 = s.rfind('0')
        k8 = s[:s.rfind("0")].rfind("0")
        s1 = s[:k7] + s[(k7 + 1):]
        m = s1.rfind('0')
        s2 = s1[:m] + s1[(m + 1):]
        if len(s2) > 0 and s2[0] == '0':
            for i in range(1, len(s2)):
                if s2[i] != '0':
                    z = i
                    break
        answer = min(answer, 2 * n - 3 - k7 - k8 + z)
    if answer == 1000:
        return -1
    return answer


l = input()
print(permutate(l))
