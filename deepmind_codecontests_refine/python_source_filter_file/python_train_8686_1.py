class Code:
    def __init__(self):
        self.n, self.m = list(map(int, input().split()))
        self.arr = []
        for _ in range(self.n):
            self.arr.append(list(input()))

    def process(self):
        for i in range(self.n):
            for j in range(self.m):
                if self.arr[i][j] == '.':
                    self.arr[i][j] = 'W' if i + j % 2 == 1 else 'B'
        for i, row in enumerate(self.arr):
            for j, ch in enumerate(row):
                print(ch, end='')
            print()


if __name__ == '__main__':
    code = Code()
    code.process()
