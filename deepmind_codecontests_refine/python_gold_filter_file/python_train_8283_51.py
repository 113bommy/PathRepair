#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @Author: wjh
# @Date:   2017-03-31 23:26:44
# @Last Modified by:   wjh
# @Last Modified time: 2017-03-31 23:36:16

op = [int.__xor__, int.__or__, int.__and__]

l = [int(input()) for _ in range(4)]
r = op[0](op[2](op[0](l[0], l[1]), op[1](l[2], l[3])), op[1](op[2](l[1], l[2]), op[0](l[0], l[3])))
print(r)