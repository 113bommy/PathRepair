class Dice:
    def __init__(self):
        self.omote=1
        self.sita=2
        self.migi=3
        self.ue=5
        self.hidari=4
        self.ura=6

    def North(self):
        self.omote,self.ue,self.ura,self.sita=self.sita,self.omote,self.ue,self.ura

    def East(self):
        self.omote,self.hidari,self.ura,self.migi=self.hidari,self.ura,self.migi,self.omote

    def West(self):
        self.omote,self.migi,self.ura,self.hidari=self.migi,self.ura,self.hidari,self.omote

    def South(self):
        self.omote,self.ue,self.ura,self.sita=self.ue,self.ura,self.sita,self.omote

    def Right(self):
        self.sita,self.migi,self.ue,self.hidari=self.migi,self.ue,self.hidari,self.sita

    def Left(self):
        self.sita,self.hidari,self.ue,self.migi=self.hidari,self.ue,self.migi,self.sita

n=int(input())
while(n!=0):
    sum=1
    dice=Dice()
    dice_def={"North":dice.North,"East":dice.East,"South":dice.South,"West":dice.West,"Right":dice.Right,"Left":dice.Left}
    for i in range(n):
        dice_def[input()]()
        sum+=dice.omote
    print(sum)
    n=int(input())