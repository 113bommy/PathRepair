class Dice:
    def __init__(self, num_list):
        self.faces = num_list

    def find_rf(self, top, front):
        tf = str(self.faces.index(top)) + str(self.faces.index(front))
        if tf in '12431':
            return self.faces[0]
        elif tf in '03520':
            return self.faces[1]
        elif tf in '01540':
            return self.faces[2]
        elif tf in '04510':
            return self.faces[3]
        elif tf in '02530':
            return self.faces[4]
        else:
            return self.faces[5]

num_list = tuple(map(int, input().split()))

dice = Dice(num_list)

q = int(input())

for i in range(q):
    top, front = map(int, input().split())
    right_face = dice.find_rf(top, front)
    print(right_face)