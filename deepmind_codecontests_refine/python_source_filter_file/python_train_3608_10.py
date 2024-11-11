

def inp():
    l = input()
    g = list(map(int, input().split()))
    return l, g


def a1(l, A):
    S = sum(A)
    s = 0
    for j, i in enumerate(A):
        s += i
        #print(S, s, j)
        if S // s <= 2:
            print(j + 1)
            break

a1(*inp())   
