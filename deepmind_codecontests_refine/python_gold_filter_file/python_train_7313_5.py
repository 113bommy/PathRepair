from sys import stdin, stdout

# 42 7
# 4 5 6 7 8 9 10 11 = 42
# 99 2
# 7997 7998 7999
# 32   33   34
# 99 => 9**11
# 0 1 2 3 4 5 6 7 8 9
# x x+1 x+2 x+3.....x+9 = n
# 1 2 3 4 5 6 7 8 9 | 0
#
# x+1 x+2 x+3..
# 109(x) => 110 => x-9y+1
# 1999(x) => 2000 => x-9y+1
# 111 => 120
# 191 => 200 (-9)
#
# k = 6
# x-4 + x-3 + x-2 + x-1 + x + x-9y+1 + x-9y+2 = n
# (k+1)x - 18y -3 -4 = n
# x = (n + 18y + 3 + 4)/(k+1)

# 99 2
# x-2  x-1  x
# 3x - 3 = 99 => x = 34 => 7999 => x-2 = 7997
# x-1 x x-9y+1
# 3x - 9y = 99 => x = 36 => 19989 => x-1 = 19988
# x x-9y+1 x-9y+2
# 3x - 18y + 3 = 99 => 19899

# 150 => 9*20

# Kx - 9*Ny = B
# x = (B + 9*Ny) / K
# (B + 9Ny) % K

# ex:
# 79297   79298   79299   79300   79301
# 7929[7] 7929[8] 7929[9] 7930[0] 7930[1] => end
# [79]297 [79]298 [79]299 [79]300 [79]301 => head
# 792[9]7 792[9]8 792[9]9 79300    79301 => cnt, s
# 79[2]97 79[2]98 79299   79[3]00  79[3]01 => nd, nd+1

if __name__ == '__main__':

    def get(s):
        return str(s%9) + '9'*(s//9)

    def sum_of_digits(n, k):

        k += 1
        res = 10**100

        for d in range(10):

            end = 0
            for i in range(k):
                end += (d+i) % 10

            if end > n:
                continue

            if d + k > 10:
                #case XX8, XX9, XX0
                for cnt in range(12):
                    s = 9 * cnt * (10 - d)

                    if s > n - end:
                        break

                    for nd in range(9):
                        ns = s + (10 - d)*nd + (k - (10 - d))*(nd + 1)
                        if ns > n - end:
                            break

                        if (n - end - ns) % k == 0:
                            res = min(res, int(get((n - end - ns) // k) + str(nd) + '9' * cnt + str(d)))

            else:
                #case XX0, XX1, XX2
                if (n - end) % k == 0:
                    res = min(res, int(get((n - end)//k) + str(d)))

        if res == 10**100:
            return -1
        else:
            return res


    t = int(stdin.readline())
    for i in range(t):
        n, k = map(int, stdin.readline().split())
        stdout.write(str(sum_of_digits(n, k)) + '\n')
