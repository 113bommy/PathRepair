production = True

import sys, math, collections

def input(input_format = 0, multi = 0):

    if multi > 0: return [input(input_format) for i in range(multi)]
    else:
        next_line = sys.stdin.readline()[:-1]

        if input_format >= 10:
            use_list = False
            input_format = int(str(input_format)[-1])
        else: use_list = True

        if input_format == 0: formatted_input = [next_line]
        elif input_format == 1: formatted_input = list(map(int, next_line.split()))
        elif input_format == 2: formatted_input = list(map(float, next_line.split()))
        elif input_format == 3: formatted_input = list(next_line)
        elif input_format == 4: formatted_input = list(map(int, list(next_line)))
        elif input_format == 5: formatted_input = next_line.split()
        else: formatted_input = [next_line]

        return formatted_input if use_list else formatted_input[0]

def out(output_line, output_format = 0, newline = True):

    formatted_output = ""

    if output_format == 0: formatted_output = str(output_line)
    elif output_format == 1: formatted_output = " ".join(map(str, output_line))
    elif output_format == 2: formatted_output = "\n".join(map(str, output_line))

    print(formatted_output, end = "\n" if newline else "")

def log(*args):
    if not production:
        print("$$$", end = "")
        print(*args)

enu = enumerate

ter = lambda a, b, c: b if a else c

def mapl(iterable, format = 0):
    
    if format == 0: return list(map(int, iterable))
    elif format == 1: return list(map(str, iterable))
    elif format == 2: return list(map(list, iterable))
#
#   >>>>>>>>>>>>>>> START OF SOLUTION <<<<<<<<<<<<<<
#


def solve():

    mod = 998244353
    n, m = input(1)
    a = input(1)
    b = input(1)

    pa = n - 1

    f = []
    c = 1

    for pb in range(m - 1, -1, -1):
        if pa < 0:
            out(0)
            break

        while a[pa] > b[pb]:
            pa -= 1
            if pa < 0:
                out(0)
                return

        log(pb, pa)
        if a[pa] != b[pb]:
            out(0)
            return
        
        pa -= 1
        if pa >= 0:
            log("a", a[pa], b[pb], pa)

            while a[pa] >= b[pb]:
                c += 1
                pa -= 1
                if pa < 0:
                    c = 1
                    break
        
        f.append(c)
        c = 1
    
    log("p", pa)
    if pa >= 0:
        out(0)
        return

    log(f)
    t = 1
    for i in f:
        t *= i
        t %= mod

    out(t)
    
    return


#for i in range(input(11)): solve()
solve()

#
#   >>>>>>>>>>>>>>>> END OF SOLUTION <<<<<<<<<<<<<<<
#
