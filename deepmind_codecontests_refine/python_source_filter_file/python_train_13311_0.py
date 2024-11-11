#! /usr/bin/python3

m=100
for _ in range(int(input())):
    m = int(m*1.05+0.9)
print(m*1000)