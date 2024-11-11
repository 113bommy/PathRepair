# Phone Numbers
def phone(s):
    ans = 0
    n = len(s)
    while True:
        if s.count('8') == 0 or n < 10:
            return ans
        s = s.replace('8', '', 1)
        n -= 11
        ans += 1
    return ans


n = int(input())
s = input()
print(phone(s))
