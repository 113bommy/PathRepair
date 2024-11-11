#!/usr/bin/python
import re
import inspect
from sys import argv, exit
from copy import copy

def rstr():
    return input()

def rint():
    return int(input())

def rints(splitchar=' '):
    return [int(i) for i in input().split(splitchar)]

def varnames(obj, namespace=globals()):
    return [name for name in namespace if namespace[name] is obj]

def pvar(var, override=False):
    prnt(varnames(var), var)

def prnt(*args, override=False):
    if '-v' in argv or override:
        print(*args)

class Candy():
    def __init__(self, stuff):
        self.type = bool(stuff[0])
        self.height = stuff[1]
        self.mass = stuff[2]

    def __str__(self):
        return '{} h{} m{}'.format(self.type, self.height, self.mass)

    def __repr__(self):
        return str(self)

def main(h, candies, last_type):
    eaten = []
    neaten = 0

    edible = sorted([c for c in candies if c.height <= h and c.type != last_type], key=lambda c: c.mass)
    prnt('h',h)
    prnt('last_type',last_type)
    prnt('edible',edible)

    while True:
        if edible:
            candy = edible.pop(-1)
            candies.remove(candy)
            prnt('eaten',candy)
            eaten.append(candy)
            neaten += 1
            last_type = not last_type
            h += candy.mass
        else:
            break
        edible = sorted([c for c in candies if c.height <= h and c.type != last_type], key=lambda c: c.mass)
        prnt(edible)
    return neaten

if __name__ == '__main__':
    (n, h) = rints()
    # type, height, mass
    candies = [Candy(rints()) for i in range(n)]
    prnt(candies)

    one = main(h, copy(candies), False)
    two = main(h, copy(candies), True)

    pvar(one)
    pvar(two)

    print(max(one, two))
