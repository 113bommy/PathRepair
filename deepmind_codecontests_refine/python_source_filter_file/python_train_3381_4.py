__author__ = 'eunice'


class A:
    def isPosible(self, a, b, s):
        distance = abs(a) + abs(b)
        s -= distance
        if (s >= 0) & (s % 2) == 0:
            return "Yes"
        else:
            return "No"

if __name__ == "__main__":
    inputValues = input().split(' ')
    print(A().isPosible(int(inputValues[0]), int(inputValues[1]), int(inputValues[2])))