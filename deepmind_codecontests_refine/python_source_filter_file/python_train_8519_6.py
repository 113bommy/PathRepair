length = int(input())
target = [int(n) for n in input().split(" ")]
if max(target) - min(target) > 1:
    print("No")
elif max(target) >= length:
    print("No")
elif max(target) - min(target) == 1 and (target.count(min(target)) == min(target) and target.count(max(target)) > 1 or (target.count(min(target)) <= min(target) and target.count(max(target)) // 2 <= max(target) - target.count(min(target)) )  ):
    print("Yes")
elif max(target) - min(target) == 0 and ( (length % 2 == 0 and min(target) * 2 <= length) or (length % 2 == 1 and 2 * (min(target) - 1) + 3 <= length)  or min(target) + 1 == length):
    print("Yes")
else:
    print("No")