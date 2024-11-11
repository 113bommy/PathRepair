class Dice:
    """サイコロを操作するクラス"""
    def __init__(self, num):
        self.num = num
    def roll_north(self):
        tmp = self.num[:]
        self.num[0] = tmp[1]
        self.num[1] = tmp[5]
        self.num[4] = tmp[0]
        self.num[5] = tmp[4]
    def roll_east(self):
        tmp = self.num[:]
        self.num[0] = tmp[3]
        self.num[2] = tmp[0]
        self.num[3] = tmp[5]
        self.num[5] = tmp[2]
    def roll_right(self):
        tmp = self.num[:]
        self.num[1] = tmp[3]
        self.num[2] = tmp[1]
        self.num[3] = tmp[4]
        self.num[4] = tmp[2]
    def print_dice(self):
        print(self.num)

dice1 = Dice(list(map(int, input().split())))
dice2 = Dice(list(map(int, input().split())))
flg = False
for i in range(10):
    if flg == True:
        break
    dice2.roll_north()
    for k in range(10):
        if flg == True:
            break
        dice2.roll_east()
        for l in range(10):
            dice2.roll_right()
            if dice1.num == dice2.num:
                flg = True
                break
if flg:
    print("Yes")
else:
    print("No")
