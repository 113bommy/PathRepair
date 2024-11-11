if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        m = int(input())
        strings = []
        for i in range(m):
            strings.append(input())
        zero_count = 0
        one_count = 0
        odd_count = 0
        even_count = 0
        for s in strings:
            for c in s:
                if c == '0':
                    zero_count += 1
                elif c == "1":
                    one_count += 1

            if len(s) % 2 == 0:
                even_count += 1
            else:
                odd_count += 1
        ans = len(strings)
        if odd_count == 0:
            if one_count % 2 != 0 or zero_count % 2 != 0:
                ans -= 1
        else:
            odity_count = 0
            if zero_count % 2 == 1:
                odity_count += 1
            if one_count % 2 == 1:
                odity_count += 1
            if odd_count % 2 != odity_count:
                ans -= 1
        print(ans)





