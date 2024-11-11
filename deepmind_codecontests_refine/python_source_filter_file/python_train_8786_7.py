#!/usr/bin/env python3
# -*- coding: utf-8 -*-
def inputi():
	a = input().split(" ")
	return [int(i) for i in a]
m = inputi()
c = inputi()
x,y = inputi()
s = 0
sumall = 0
ok = 0
for a in c:
	sumall=sumall+a
answer = 0
for a in c:
	s=s+a
	answer=answer+1
	if x<=s<=y and x<=sumall-s<=y:
		print(answer)
		ok = 1
		break
if ok is not 1: print(0)