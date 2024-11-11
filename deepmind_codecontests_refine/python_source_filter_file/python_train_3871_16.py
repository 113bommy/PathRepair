def int_multiple():
    return  [int(c) for c in input().split()]

def int_single():
    return int(input())

def str_multiple():
    return [c for c in input().split()]

def str_single():
    return input()

# start

n, k = int_multiple()

l = int_multiple()

l = sorted(l)

mid = int(n/2)

l = l[mid:]

acc = []
r = 0
for i in range(len(l)):
    r += l[i]
    acc.append(r)

ans = 0
for i in reversed(range(len(l))):
    need = l[i] * (i+1)
    hand = acc[i] + k
    if hand >= need:
        left = hand - need
        additional = int(left / (mid+1))
        ans = l[i] + additional
        break

print(ans)
