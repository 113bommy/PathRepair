class Code:
    def __init__(self):
        self.n = int(input())
        self.dp = []

    def fib(self):
        self.dp.extend([1, 1])
        while self.dp[-1] <= self.n:
            self.dp.append(self.dp[-1] + self.dp[-2])

    def process(self):
        self.fib()
        flag = 0
        for i in range(0, len(self.dp)):
            for j in range(0, len(self.dp)):
                for k in range(0, len(self.dp)):
                    if self.dp[i] + self.dp[j] + self.dp[k] == self.n:
                        flag = 1
                        print(self.dp[i], self.dp[j], self.dp[k])
                        return
                    elif self.dp[i] + self.dp[j] + self.dp[k] > self.n:
                        break
                if self.dp[i] + self.dp[j] > self.n:
                    break
        if flag == 0:
            print("I'm too stupid to solve this problem")


if __name__ == '__main__':
    code = Code()
    code.process()
