import time
# [int(x) for x in input().split()]


def timer(func):
    def f(*args, **kwargs):
        start_time = time.time()
        ret = func(*args, **kwargs)
        print("--- %s seconds ---" % (time.time() - start_time))
        return ret
    return f



def main():
    k = int(input())
    # k = 1000
    result = ''
    f = [1,1]
    for i in range(1, k+1):
        if i == f[-1]:
            f.append(f[-1] + f[-2])
            result += 'O'
        else:
            result += 'o'
    print(result)


main()