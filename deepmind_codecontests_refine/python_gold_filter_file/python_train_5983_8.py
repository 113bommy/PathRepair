'''input
10 6
abcdefdcba
'''
# I am Mr.Inconsistent 
from sys import stdin
import math


def check_pallindrome(string):
	#print(string)
	i = 0
	j = len(string) - 1
	while i < j:
		if string[i] != string[j]:
			return False
		i += 1
		j -= 1
	return True


def magic(c, d):
	if ord(c) > ord(d):
		return min(ord(c) - ord(d), ord('z') - ord(c) + ord(d) - ord('a') + 1)
	else:
		c, d = d, c
		return min(ord(c) - ord(d), ord('z') - ord(c) + ord(d) - ord('a') + 1)


def difference(type, index, string, order):
	if type == 1:
		steps = 0
		mov = 0
		i = index
		j = len(string) - index - 1
		while i >= 0:
			if string[i] != string[j]:
				steps += magic(string[i], string[j])
				steps -= mov
				mov = index - i
				steps += mov
			j += 1
			i -= 1
		if check_pallindrome(string[index + 1: len(string) // 2 ] + string[len(string) // 2: len(string) - index - 1]) == False:
			if order:
				steps += mov

	elif type == 2:
		steps = 0
		mov = 0
		i = index
		j = len(string) - index - 1
		while i < len(string) // 2:
			if string[i] != string[j]:
				steps += magic(string[i], string[j])
				steps -= mov
				mov = i - index
				steps += mov
			j -= 1
			i += 1
		if check_pallindrome(string[: index] + string[len(string) - index :])== False:
			if order:
				steps += mov

	return steps


def add(num):
	if num > 0:
		return num + 1
	return num

def remove_odd(string, p):
	n = len(string)
	if n % 2 == 1:
		if p > n // 2:
			p -= 1
		return string[: n// 2] + string[n // 2 + 1:], p
	else:
		return string, p


# main starts
n, p = list(map(int, stdin.readline().split()))
string = stdin.readline().strip()
if len(string) == 1:
	print(0)
	exit()


count = 0
p = p - 1
if n % 2 == 1 and p == n // 2:
	count += 1
	p -= 1
string, p = remove_odd(string, p)
if p >=  len(string) // 2:
	p = len(string) - p - 1
#print(p, string)
cnt_1 = difference(1, p, string, True) + add(difference(2, p + 1, string, False))
#print('count_1', cnt_1)
cnt_2 = difference(2, p, string, True) + add(difference(1, p - 1, string, False))
#print('count_2', cnt_2)
count += min(cnt_1, cnt_2)
print(count)
