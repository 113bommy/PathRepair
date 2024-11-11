from sys import stdin, stdout
print = stdout.write
input = stdin.readline


class Node:
    def __init__(self, start, end, min, max):
        self.start, self.end = start, end
        self.min, self.max = min, max

    def __repr__(self):
        return f"{self.start}-{self.end} (min:{self.min}, max: {self.max})\n"

class BinaryTree:
    def __init__(self, array, length):
        self.array = [None for _ in range(self.get_msb(length)-1)] + \
                     [Node(i, i, array[i], array[i]) for i in range(length)] + \
                     [None for _ in range(self.get_msb(length)-length)]
        for i in range(len(self.array)//2-1, -1, -1):
            left = (i<<1) + 1
            right = left+1
            left, right = self.array[left], self.array[right]
            if left is None:
                continue
            else:

                start, end = left.start, left.end
                _min, _max = left.min, left.max
                if right is not None:
                    end = right.end
                    _min, _max = min(_min, right.min), max(_max, right.max)

                node = Node(start, end, _min, _max)
                self.array[i] = node
        print(str(self.array))

    def get_msb(self, n):
        if not n:
            return 0

        msb = 1

        while (n > 1):
            n = n>>1
            msb += 1

        return (1 << msb)

def solve_test():
    n = int(input())
    a = [int(x) for x in input().split()]
    _max = 0
    for i in range(n-1):
        _max = max(_max, a[i]*a[i+1])
    return _max

def main(args=None):
    tests = int(input())
    for _ in range(tests):
        print(f"{solve_test()}\n")

if __name__ == '__main__':
    main()