def solve(s):
    i = len(s) - 1
    while i >= 0:
        try:
            if s[i] == '4':
                if s[i-1] == '1':
                    i -= 1
                elif s[i-2:i] == '14':
                    i -= 2
                else:
                    return "NO"
            elif s[i] == '1':
                i -= 1
            else:
                return "NO"
        except:
            return "NO"
    return "YES"
        


def main():
    s = input()
    print(solve(s))


main()
