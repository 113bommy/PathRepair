from fractions import gcd

class Monitor:
    @staticmethod
    def read_input():
        a_b_x_y = list(map(int, input('').split()))
        return a_b_x_y[0], a_b_x_y[1], a_b_x_y[2], a_b_x_y[3]

    @staticmethod
    def compute_ratio(a, b, x, y):
        g = gcd(x,y)
        x, y = x/g, y/g
        m = min(a/x, b/y)
        a, b = int(x*m), int(y*m)
        print(a, b)

    @staticmethod
    def run():
        a, b, x, y = Monitor.read_input() 
        if a <= 1 and b <= 1:
            print(0, 0)
        elif float(a/b) == float(x/y):
            print(a, b)
        else:
            Monitor.compute_ratio(a,b,x,y)
        

if __name__ == "__main__":
    Monitor.run()