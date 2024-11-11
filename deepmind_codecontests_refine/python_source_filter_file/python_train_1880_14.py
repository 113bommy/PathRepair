class Dice:
    def __init__(self, data):
        self.data = data

    def __eq__(self, value):

            
        for i in range(4):
            if self.data[0] == value.data[0]:
                for j in range(4):
                    if self.data == value.data:
                        return True
                    self.move('R')
            self.move('E')

        for i in range(4):
            if self.data[0] == value.data[0]:
                for j in range(4):
                    if self.data == value.data:
                        return True
                    self.move('R')
            self.move('N')
        return False

    def move(self, direction):
        if direction == 'E':
            self.data[0],self.data[3], self.data[5], self.data[2] = \
                self.data[3],self.data[5], self.data[2], self.data[0] 
        elif direction == 'N':
            self.data[0],self.data[1], self.data[5], self.data[4] = \
                self.data[1],self.data[5], self.data[4], self.data[0]
        elif direction == 'S':
            self.data[0],self.data[1], self.data[5], self.data[4] = \
                self.data[4],self.data[0], self.data[1], self.data[5]
        elif direction == 'W':
            self.data[0],self.data[2], self.data[5], self.data[3] = \
                self.data[2],self.data[5], self.data[3], self.data[0]
        elif direction == 'R':
            self.data[1],self.data[2], self.data[4], self.data[3] = \
                self.data[2],self.data[4], self.data[3], self.data[1]

a = []
for i in range(int(input())):
    a += [Dice(input().split())]

p = 'Yes'
for i in range(len(a) - 1):
    for j in range(i,len(a)):
        if a[i] == a[j]:
            p = 'No'
            break
print(p)