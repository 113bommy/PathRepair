import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    n=int(input())
    if n>=-128 and n<=127:
        print("byte")
    elif n>=-32768 and n<=32767:
        print("short")
    elif n>=2147483648 and n<=2147483647:
        print("int")
    elif n>=9223372036854775808 and n<=9223372036854775807:
        print("long")
    else:
        print("BigInteger")