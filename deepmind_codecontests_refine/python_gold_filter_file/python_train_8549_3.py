from time import time


def rrr(inpstr):
    flag = True
    t = []
    for c in inpstr:
        if len(t) > 0:
            if c == t[-1]:
                t.pop()
                flag = not flag
                continue
        t.append(c)
    return flag


if __name__ == "__main__":

    s = input()
    #s = "abcdefghik" * 1000

    t1 = time()

    is_first = rrr(s)
    print("No" if is_first else "Yes")
    t2 = time()
    #print(t2-t1)
