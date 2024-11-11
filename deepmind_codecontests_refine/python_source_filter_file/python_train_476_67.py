s, v1, v2, t1, t2 = map(int, input().split())
duration1 = s * v1 + t1 * 2
duration2 = s * v2 + t2 * 2
if duration1 < duration2:
    print("Frist")
elif duration1 > duration2:
    print("Second")
else:
    print("Friendship")