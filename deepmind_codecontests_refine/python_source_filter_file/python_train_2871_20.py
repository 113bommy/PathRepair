def solve(list,length):
    res = [None]*length
    for order, val in enumerate(list):
        if order > length - order - 1:
            break;
        if order%2==0:
            res[order] = val
            res[length - order - 1] = list[length - order - 1] 
        else:
            res[length - order - 1] = val
            res[order] = list[length - order -1]
    return [str(i) for i in res]

def main():
    a = int(input())
    b = [int(a) for a in input().split(' ')]
    print(' '.join(solve(b,a)))

main()
