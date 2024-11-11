import sys


def det(mat):
  t = 1 / (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0])
  a = t * mat[1][1]
  b = t * -1 * mat[0][1]
  c = t * -1 * mat[1][0]
  d = t * mat[0][0]
  return [[a, b], [c, d]]


for line in sys.stdin:
  try:
    a, b, c, d, e, f = [int(i) for i in line.split()]
    A = [[a, b], [d, e]]
    P = [c, f]
    detA = det(A)
    print("%lf %lf" % (detA[0][0] * P[0] + detA[0][1] * P[1], detA[1][0] * P[0] + detA[1][1] * P[1]))
  except:
    break