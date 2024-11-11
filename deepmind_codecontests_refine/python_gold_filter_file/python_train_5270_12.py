class Solver:
    def main(self):
        s = input()
        ls = len(s)

        vowels = 'aeiou'
        cnt = 0
        breaks = []
        same = 0

        for i in range(0, ls):
            if s[i] in vowels:
                cnt = 0
                same = 0
            elif i > 0 and s[i-1] == s[i]:
                same += 1
                cnt = cnt
            else:
                cnt += 1

            if same + cnt >= 3 and cnt >= 2:
                breaks.append(i)
                cnt = 1
                same = 0

        lbreaks = len(breaks)
        current = 0
        for i in range(ls):
            if current < lbreaks and i == breaks[current]:
                print(' ', end='')
                current += 1
            print(s[i], end='')

        print()


Solver().main()
