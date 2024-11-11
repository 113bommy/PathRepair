# It's all about what U BELIEVE
import sys
input = sys.stdin.readline
def gint(): return int(input())
def gint_arr(): return list(map(int, input().split()))
def gfloat(): return float(input())
def gfloat_arr(): return list(map(float, input().split()))
def pair_int(): return map(int, input().split())
###############################################################################
INF = (1 << 31)
MOD = "1000000007"
dx = [-1, 0, 1,  0]
dy = [ 0, 1, 0, -1]
############################ SOLUTION IS COMING ###############################
a = input()
b = input()
c = input()
v = ['a', 'i', 'e', 'o', 'u']
cnt = [5, 7, 5]
print("yes" if [sum(a.count(x) for x in v),
                sum(b.count(x) for x in v),
                sum(c.count(x) for x in v)] == cnt
      else "NO"
      )
