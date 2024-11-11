__author__ = 'Alexander'

def Task(inp1):
    n = int(inp1)
    sqr = [1]
    least = 1
    for i in range(2, 8):
        least = i
        sqr.append(i*i)
        if n >= sqr[i-2] and n < sqr[i-1]:
            break
    least -= 1
    resid = n - sqr[-2]
    if resid == 0:
        res = least*4
    elif resid <= least:
        res = least*4 + 2
    else:
        res = least*4 + 4
    return res

def Main():
    inp1 = input()
    outp = Task(inp1)
    print("{}\n".format(outp))

def Test():
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert Task(4) == 8

Main()
# Test()