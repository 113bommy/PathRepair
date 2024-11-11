from sys import stdin, stdout
import cProfile,math

printHeap = str()
test = False
memory_constrained = False


def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")


def test_print(output):
    if test:
        stdout.write(str(output) + "\n")


def display_list(list1, sep=" "):
    stdout.write(sep.join(map(str, list1)) + "\n")


def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))


memory = dict()


def clear_cache():
    global memory
    memory = dict()


def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result


# ----------------------------------------------------------------------------------- MAIN PROGRAM

from collections import Counter
def main():
    n = get_int()
    a = [100005]
    c = [100005]
    b = [100005]
    ab = [100005]
    bc = [100005]
    ca = [100005]
    abc = [100005]
    for _ in range(n):
        x, y = stdin.readline().strip().split()
        x, y = int(x), str(y)
        if ("A" in y and "B" in y and "C" in y):
            abc.append(x)
        elif("A" in y and "B" in y):
            ab.append(x)
        elif ("B" in y and "C" in y):
            bc.append(x)
        elif ("A" in y and "C" in y):
            ca.append(x)
        elif ("A" in y):
            a.append(x)
        elif ("B" in y):
            b.append(x)
        elif ("C" in y):
            c.append(x)
    z = min(min(a) + min(bc), min(b) + min(ca), min(c) + min(ab), min(abc), min(a)+min(b)+min(c), min(ab) + min(bc), min(ca) + min(bc), min(ab) + min(ca), min(ab)+min(bc)+min(ca))
    print(z if z<100005 else -1)






















# --------------------------------------------------------------------------------------------- END


cProfile.run('main()') if test else main()