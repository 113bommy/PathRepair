nm = input()
n = [int(x) for x in input().split(" ")]
m = [int(x) for x in input().split(" ")]

nOdd = sum(1 for x in n if x % 2 == 1)
nEven = len(n) - nOdd

mOdd = sum(1 for x in m if x % 2 == 1)
mEven = len(m) - mOdd

ans = min(nOdd, mEven) + min(nEven, mOdd)

print(ans)
