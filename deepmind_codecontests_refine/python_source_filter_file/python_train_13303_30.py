t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

ave_a, ave_b = t1 * a1 + t2 * a2, t1 * b1 + t2 * b2
if ave_a < ave_b:
    a1, a2, b1, b2 = b1, b2, a1, a2
    ave_a, ave_b = ave_b, ave_a

if ave_a == ave_b:
    print('infinity')
    exit()

first, second = t1 * (b1 - a1), ave_a - ave_b
ans = first // second * 2 + (first % second != 0)
print(ans)
