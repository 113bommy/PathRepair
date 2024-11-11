from sys import exit,stdin,stderr
def rl():
    return [int(w) for w in stdin.readline().split()]

n, = rl()
print(7 * n + 8)
print(0, 0)
for i in range(n + 1):
    print(2*i+1, 2*i)
    print(2*i+2, 2*i)
    print(2*i+2, 2*i+1)
    print(2*i+2, 2*i+2)
    print(2*i+1, 2*i+2)
    print(2*i, 2*i+2)
    print(2*i, 2*i+1)
