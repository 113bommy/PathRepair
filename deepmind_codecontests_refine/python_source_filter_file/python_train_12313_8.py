class Square():
    point1 = []
    point2 = []
    number = 0

    def GenerateCords(self, a, x):
        self.number = x
        if x == 1:
            self.point1 = [(-a/2), 0]
        elif x%3 == 2:
            self.point1 = [(-a/2),((((x//3)*2)+1)*a)]
        elif x%3 == 0:
            self.point1 = [-a,(((((x//3)-1)*2)+2)*a)]
        else:
            self.point1 = [0,(((((x//3)-1)*2)+2)*a)]

        self.point2 = [(self.point1[0]+a),(self.point1[1]+a)]

    def CheckIfIn(self, x, y):
        if x < self.point1[0]+1 or x > self.point2[0]:
            return -1
        if y < self.point1[1]+1 or y > self.point2[1]:
            return -1
        else:
            return self.number



a,x,y = map(int, input().split())


row = y//a + 1

if row == 1:
    test = Square()
    test.GenerateCords(a, row)
elif (row - 1)%2 == 1:
    test = Square()
    test.GenerateCords(a, ((((row-1)//2)*3)+2))
else:
    if x <= 0:
        test = Square()
        test.GenerateCords(a, (row//2)*3)
    else:
        test = Square()
        test.GenerateCords(a, ((row//2)*3)+1)

print(test.CheckIfIn(x,y))
    
