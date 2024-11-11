#!/usr/bin/env python

def main():
    N, Z, W = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    
    if N == 1:
        print(abs(a[0] - W))
    else:
        print(max(abs(a[0] - W), abs(a[N - 2] - a[N - 1])))

if __name__ == '__main__':
    main()
