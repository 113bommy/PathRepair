# list input
def linp(): return list(map(int, input().split()))


# map input
def minp(): return map(int, input().split())


# int input
def iinp(): return int(input())


# no of testcase
def test(): return int(input())


# normal input
def inp(): return input()

def fun(l, curr, res):
    while l:
        if l[0]> curr and l[-1]>curr:
            if l[0] < l[-1]:
                curr = l.pop(0)
                res+= 'L'
            elif l[-1] > l[0]:
                curr = l.pop()
                res += 'R'
            else:
                pass
        elif l[0]> curr:
            curr = l.pop(0)
            res += 'L'
        elif l[-1] > curr:
            curr = l.pop()
            res += 'R'
        else:
            break
    return res



def solve():
    # write your solution for one testcase
    n = iinp()
    l = linp()
    curr = -1
    res = ''
    while l:
        if l[0]> curr and l[-1]>curr:
            if l[0] < l[-1]:
                curr = l.pop(0)
                res+= 'L'
                n-=1
            elif l[0] > l[-1]:
                curr = l.pop()
                res += 'R'
                n-=1
            else:
                flag = 'L'
                i, j = 0, n-1

                counti, countj = 0, 0
                while i < n-1 and j >0:
                    flag1 = True
                    if l[i+1] > l[i]:
                        counti += 1
                        i+=1
                        flag1 =False
                    if l[j-1] > l[j]:
                        countj += 1
                        j-=1
                        flag1 = False
                    if counti>countj:
                        flag = 'L'
                        break
                    elif countj>counti:
                        flag = 'R'
                        break
                    if flag1:
                        break
                # print(flag)
                if flag == 'L':
                    curr = l.pop(0)
                    res += 'L'
                else:
                    curr = l.pop()
                    res += 'R'

        elif l[0]> curr:
            curr = l.pop(0)
            res += 'L'
            n-=1
        elif l[-1] > curr:
            curr = l.pop()
            res += 'R'
            n-=1
        else:
            break
    print(str(len(res)) + '\n' + res)





def main():
    # for _ in range(test()):
        solve()


if __name__ == '__main__':
    main()
