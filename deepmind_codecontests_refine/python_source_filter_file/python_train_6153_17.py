class Node:
    x = 0.0
    y = 0.0

    def __init__(self, x, y):
        self.x = x
        self.y = y


class InOrOut:
    esp = 0.00000001
    coor = []

    def __init__(self):
        n, m = [float(i) for i in input().split(' ')]
        self.n = n
        self.m = m
        self.coor.append(Node(0, m))
        self.coor.append(Node(m, 0))
        self.coor.append(Node(n, n-m))
        self.coor.append(Node(n-m, n))

    def get_len(self, node1, node2):
        ans = (((node1.x - node2.x)**2) + ((node1.y - node2.y)**2)) ** 0.5
        return ans

    def get_s(self, node1, node2, node3):
        len1 = self.get_len(node1, node2)
        len2 = self.get_len(node1, node3)
        len3 = self.get_len(node2, node3)
        p = (len1 + len2 + len3) / 2.0

        s = (p * abs(p-len1) * abs(p-len2) * abs(p-len3)) ** 0.5
        return s

    def if_equal(self):
        are = self.get_len(self.coor[0], self.coor[1]) * self.get_len(self.coor[0], self.coor[3])
        q = int(input())
        for i in range(0, q):
            x1, y1 = [float(i) for i in input().split(' ')]
            now = Node(x1, y1)
            ss = 0.0
            for k in range(0, 4):
                k2 = (k + 1) % 4
                ss += self.get_s(now, self.coor[k], self.coor[k2])

            cha = ss - are
            if cha < 0:
                cha = -cha
            if cha > self.esp:
                print("NO")
            else:
                print('YES')


if __name__ == "__main__":
    temp = InOrOut()
    temp.if_equal()