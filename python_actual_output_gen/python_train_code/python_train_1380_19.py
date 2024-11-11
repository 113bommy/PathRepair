#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2015 missingdays <missingdays@missingdays>
#
# Distributed under terms of the MIT license.

"""

"""

inp = input().split()
n = int(inp[0])
w = int(inp[1])

cups = sorted(list(map(int, input().split())))

girl = cups[0]
boy = cups[n]

s = 0

s += (min(girl, boy / 2) * 3 * n)

print(s)    
