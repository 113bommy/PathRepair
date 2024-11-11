#! /usr/bin/env python
from enum import Enum

def read_input():
    sx, sy = [int(i) for i in input().split()]
    dx, dy = [int(i) for i in input().split()]
    n = int(input())
    wind = [i for i in input()]
    return sx, sy, dx, dy, n, wind

class Direction(Enum):
    L = 0
    R = 1
    D = 2
    U = 3
    
def gen_prefix_sum(x_wind, y_wind, wind, n):
    
    prefix_sum = []
    direction = getattr(Direction, wind[0]).value
    prefix_sum.append((x_wind[direction], y_wind[direction]))
    for i in range(1, n):
        direction = getattr(Direction, wind[i]).value
        prefix_sum.append((prefix_sum[i-1][0] + x_wind[direction],
         prefix_sum[i-1][1] + y_wind[direction]))
    return prefix_sum
        

def get_distance(k, sx, sy, fx, fy, prefix_sum, n):
    count = (k - 1) // n
    rem = (k - 1) % n
    x_wind_component = sx + prefix_sum[n-1][0] * count + prefix_sum[rem][0]
    y_wind_component = sy + prefix_sum[n-1][1] * count + prefix_sum[rem][1]
    # print(k, count, rem, end=' ')
    # print(x_wind_component, y_wind_component)
    dist = abs(fx - x_wind_component) + abs(fy - y_wind_component)
    return dist

def test_func():
    for i in range(1, int(1e18)):
        wind = 'UUU'
        n = len(wind)
        x_wind = [-1, 1, 0, 0]
        y_wind = [0, 0, -1, 1]
        prefix_sum = gen_prefix_sum(x_wind, y_wind, wind, n)
        
        dist = get_distance(i, 0, 0, 4, 6, prefix_sum, n)
        if dist > i:
            print(i, dist)

def process():
    sx, sy, fx, fy, n, wind = read_input()
    x_wind = [-1, 1, 0, 0]
    y_wind = [0, 0, -1, 1]
    prefix_sum = gen_prefix_sum(x_wind, y_wind, wind, n)
    # print(sx, sy, fx, fy, n, wind, prefix_sum)

    def binary_search(l, r):
        
        if l < r:
            mid = (l + r) // 2
            dist = get_distance(mid, sx, sy, fx, fy, prefix_sum, n)
            if dist <= mid:
                return binary_search(l, mid)
            else:
                return binary_search(mid+1, r)
        else:
            return r
    
    value = binary_search(0, int(1e18))
    if value > int(5e17):
        print(-1)
    else:
        print(value)

def main():
    process()

if __name__ == "__main__":
    main()
    