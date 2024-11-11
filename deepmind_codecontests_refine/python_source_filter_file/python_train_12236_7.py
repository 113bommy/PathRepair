from sys import *
inp = lambda : stdin.readline()

def main():
    n,a,b = [int(i) for i in inp().split()]
    a = a + b
    while a < 0 : a += n
    while a > n : a -= n
    print(a)

if __name__ == "__main__":
    main()