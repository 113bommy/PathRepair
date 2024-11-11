#!/usr/bin/python
# -*- coding: UTF-8 -*-

def main():
	n = input()
	a = input().split(" ")*1
	num_1 = a.index('1') + 1
	num_max = a.index(max(a)) + 1
	max_len = 0
	if (max_len < num_max - 1):
		max_len = num_max - 1
	if (max_len < num_1 - 1):
		max_len = num_1 - 1
	if (max_len < len(a) - num_max):
		max_len = len(a) - num_max
	if (max_len < len(a) - num_1):
		max_len = len(a) - num_1
	print(max_len)

if __name__ == "__main__":
    main()
