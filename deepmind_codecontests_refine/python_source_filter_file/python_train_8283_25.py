#!/usr/bin/env python3

import sys

xs = [int(sys.stdin.readline().strip()) for _ in range(4)]

def OR(x, y):
	return x + y - x * y

def AND(x, y):
	return x * y

def XOR(x, y):
	return (x + y) % 2

def f(A, B, C):
	def h(xs):
		return A(B(A(xs[0], xs[1]), C(xs[2], xs[3])), C(B(xs[1], xs[2]), A(xs[0], xs[3])))
	return h


print (f(AND, XOR, OR)(xs))
