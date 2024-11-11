import time
# [int(x) for x in input().split()]


def timer(func):
    def f(*args, **kwargs):
        start_time = time.time()
        ret = func(*args, **kwargs)
        print("--- %s seconds ---" % (time.time() - start_time))
        return ret
    return f


@timer
def main():
    n, m = [int(x) for x in input().split()]
    servers = []
    for i in range(n):
        servers.append(input().split(' '))
    #print(servers)
    for i in range(m):
        line = input().split(' ')
        # line[1] = line[1][:-1]
        for j in range(n):
            if line[1][:-1] == servers[j][1]:
                # print(line[0], ''.join(line[1]) + ";", '#' + ''.join(servers[0]))
                print("{0} {1} #{2}".format(line[0], line[1], servers[j][0]))


main()
