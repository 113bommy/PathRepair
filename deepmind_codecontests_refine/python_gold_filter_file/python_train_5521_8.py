class Dice:
    def __init__(self):
        self.faces=[]

    def rotate(self, direction):
        tmp = self.faces.copy()

        if direction =="N":
            self.faces[5-1] = tmp[1-1]
            self.faces[1-1] = tmp[2-1]
            self.faces[2-1] = tmp[6-1]
            self.faces[6-1] = tmp[5-1]
        if direction =="S":
            self.faces[5-1] = tmp[6-1]
            self.faces[1-1] = tmp[5-1]
            self.faces[2-1] = tmp[1-1]
            self.faces[6-1] = tmp[2-1]
        if direction =="W":
            self.faces[4-1] = tmp[1-1]
            self.faces[1-1] = tmp[3-1]
            self.faces[3-1] = tmp[6-1]
            self.faces[6-1] = tmp[4-1]
        if direction =="E":
            self.faces[3-1] = tmp[1-1]
            self.faces[1-1] = tmp[4-1]
            self.faces[4-1] = tmp[6-1]
            self.faces[6-1] = tmp[3-1]
        return 0

    def spin(self):
        self.faces[4-1], self.faces[2-1],self.faces[5-1],self.faces[3-1] =\
        self.faces[2-1], self.faces[3-1],self.faces[4-1],self.faces[5-1]

        return 0

d1 = Dice()
d2 = Dice()
d1.faces=[int(x) for x in input().split(" ")]
d2.faces=[int(x) for x in input().split(" ")]
up,front = d1.faces[0], d1.faces[1]

res = "No"
#set up side
for _ in range(3):
    for _ in range(4):
        for ___ in range(4):
            #print("d1: {}".format(d1.faces))
            #print("d2: {}".format(d2.faces))
            if d1.faces == d2.faces:
                res = "Yes"
                break
            d2.spin()
        d2.rotate("W")
    d2.rotate("N")

print(res)