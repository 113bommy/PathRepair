class Dice():

    def __init__(self, label):
        self.label = label

    def north(self):
        self.change([2, 6, 3, 4, 1, 5])

    def west(self):
        self.change([3, 2, 6, 1, 5, 4])

    def east(self):
        self.change([4, 2, 1, 6, 5, 3])

    def south(self):
        self.change([5, 1, 3, 4, 6, 2])

    def rotate(self):
        self.change([1, 4, 2, 5, 3, 6])

    def change(self, convert):
        num = []
        for i in range(6):
            num.append(self.label[convert[i] - 1])
        self.label = num

    def is_same_dice(self, another_dice):
        for i in range(6):
            if i % 2 == 0:
                self.north()
            else:
                self.west()
            for j in range(4):
                self.rotate()
                if self.label == another_dice:
                    return True
        return False


def main():
    f = [int(x) for x in input().split()]
    s = [int(x) for x in input().split()]

    if Dice(f).is_same_dice(s):
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()